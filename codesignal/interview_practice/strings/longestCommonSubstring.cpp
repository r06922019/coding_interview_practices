int BASE = 3;
int MOD = 1e9+7;

int mod(int x) {
    x = x % MOD;
    if(x < 0) x += MOD;
    return x;
}

int mod(long long int x) {
    x = x % MOD;
    if(x < 0) x += MOD;
    return x;
}

int add(int a, int b) {
    return mod(mod(a) + mod(b));
}

int mul(int a, int b) {
    long long int tmp = mod(a);
    tmp = tmp * mod(b);
    return mod(tmp);
}

int push_in_hash(int cur_hash, char new_char) {
    return add(mul(cur_hash, BASE), new_char);
}

bool match(string &s, vector<int> &s_hashes,
    string &t, vector<int> &t_hashes,
    int len, vector<int>  &bases) {

    unordered_map<int, vector<int>> hash_to_indexs;
    for(int i = len; i < s_hashes.size(); ++i) {
        // compute hash of s[i-len, ...., i-1]
        int s_hash = add(s_hashes[i], -mul(bases[len], s_hashes[i-len]));
        hash_to_indexs[s_hash].push_back(i-len);
    }

    for(int i = len; i < t_hashes.size(); ++i) {
        // compute hash of t[i-len, ...., i-1]
        int t_hash = add(t_hashes[i], -mul(bases[len], t_hashes[i-len]));
        if(hash_to_indexs.find(t_hash) != hash_to_indexs.end()) {
            auto &s_indexs = hash_to_indexs[t_hash];
            for(auto &s_index : s_indexs) {
                if(t.substr(i-len, len) == s.substr(s_index, len))
                    return true;
            }
        }
    }
    return false;
}

int longestCommonSubstring(string s, string t) {
    int l = 1, r = min(s.size(), t.size())+1; // should make sure the step is here
    vector<int> bases(r, 1), s_hashes{0}, t_hashes{0};
    for(int i = 1; i < r; ++i) {
        bases[i] = mul(bases[i-1], BASE);
    }
    for(auto &c : s) {
        s_hashes.push_back(add(mul(s_hashes.back(), BASE), c));
    }
    for(auto &c : t) {
        t_hashes.push_back(add(mul(t_hashes.back(), BASE), c));
    }
    while(l < r) {
        int mid = l + (r-l)/2;
        if(!match(s, s_hashes, t, t_hashes, mid, bases)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    return l-1;
}
