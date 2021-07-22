int MOD = 1e9+7;
int BASE = 3;

int mod(int x) {
    x %= MOD;
    if(x < 0) x += MOD;
    return x;
}

int mod(long long int x) {
    x %= MOD;
    if(x < 0) x += MOD;
    return x;
}

int add(int a, int b) {
    return mod(mod(a) + mod(b));
}

int mul(int a, int b) {
    long long int ans = mod(a);
    ans = ans * mod(b);
    return mod(ans);
}

int push_in_hash(int cur_hash, char new_char) {
    return add(mul(cur_hash, BASE), new_char);
}

bool string_in_string(string a, string b) { // a is in b
    int a_hash = 0, base_max = 0;
    for(auto &ch : a) {
        a_hash = push_in_hash(a_hash, ch);
        if(base_max == 0) {
            base_max = 1;
        }
        else {
            base_max = mul(base_max, BASE);
        }
    }

    int b_hash = 0;
    for(int i = 0; i < b.size(); ++i) {
        if(i >= a.size()) {
            // remove b[i - a.size()]
            b_hash = add(b_hash, -mul(b[i - a.size()], base_max));
        }
        b_hash = push_in_hash(b_hash, b[i]);
        if(i >= a.size()-1) {
            if(a_hash == b_hash && a == b.substr(i+1-a.size(), a.size())) {
                return true;
            }
        }
    }

    return false;
}

bool regexMatching(string pattern, string test) {
    if(pattern[0] == '^' && pattern.back() == '?') {
        return pattern.substr(1, pattern.size()-2) == test;
    }
    else if(pattern[0] == '^') {
        pattern = pattern.substr(1);
        if(pattern.size() > test.size()) {
            return false;
        }
        return pattern == test.substr(0, pattern.size());
    }
    else if(pattern.back() == '$') {
        pattern.pop_back();
        if(pattern.size() > test.size()) {
            return false;
        }
        return pattern == test.substr(test.size()-pattern.size());
    }
    return string_in_string(pattern, test);
}
