int BASE = 3;
int MOD = 1e9+7;

int add(int a, int b) {
    int tmp = ((a%MOD) + (b%MOD)) % MOD;
    if(tmp < 0) tmp += MOD;
    return tmp;
}

int mul(int a, int b) {
    long long int tmp = a % MOD;
    tmp = tmp * (b % MOD);
    tmp %= MOD;
    if(tmp < 0) tmp += MOD;
    return tmp;
}

int push_into_hash(int cur_hash, char c) {
    cur_hash = add(mul(cur_hash, BASE), (int)c);
    return cur_hash;
}

int push_into_hash_with_remove(int cur_hash, char c, char del, int BASE_MAX) {
    cur_hash = add(cur_hash, -mul(del, BASE_MAX));
    cur_hash = add(mul(cur_hash, BASE), (int)c);
    return cur_hash;
}

int strstr(string s, string x) {
    int x_hash = 0, BASE_MAX = 1;
    for(int i = 0; i < x.size(); ++i) {
        x_hash = push_into_hash(x_hash, x[i]);
        if(i > 0)
            BASE_MAX = mul(BASE_MAX, BASE);
    }

    int cur_hash = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(i < x.size()) {
            cur_hash = push_into_hash(cur_hash, s[i]);
        }
        else { // already x chars in hash
            cur_hash = push_into_hash_with_remove(cur_hash, s[i], s[i-x.size()], BASE_MAX);
        }
        if(cur_hash == x_hash && s.substr(i+1-x.size(), x.size()) == x)
            return i+1-x.size();
    }
    return -1;
}
