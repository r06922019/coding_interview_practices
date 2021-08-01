class Solution {
public:
    bool is_palin(string &s, int l, int r) {
        if(l < 0 || r >= s.size() || s[l] != s[r]) return false;
        while(l < r) {
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        string prefix = "";
        int n = s.size();
        for(int i = n-1; i >= 1; --i) {
            if(is_palin(s, 0, i)) {
                break;
            }
            prefix += s[i];
        }

        return prefix + s;
    }
};

class Solution {
public:
    int BASE = 3, MOD = 29;

    string shortestPalindrome(string s) {
        string r(s.rbegin(), s.rend());
        int n = s.size(), r_hash = compute_hash(r), s_hash = compute_hash(s);
        if(r_hash == s_hash && compare_arr(r, 0, s, 0, n)) return s;
        for(int i = 0; i < n; ++i) {
            // pop r[i], s[n-1-i]
            r_hash = (r_hash + MOD - (((r[i] - 'a') * safe_pow(n-1-i)) % MOD)) % MOD;

            s_hash += MOD - (s[n-1-i] - 'a');
            while(s_hash % BASE) {
                s_hash += MOD;
            }
            s_hash /= BASE;
            s_hash = s_hash % MOD;

            // compare
            if(r_hash == s_hash && compare_arr(r, i+1, s, 0, n-1-i)) return r.substr(0, i+1) + s;
        }
        return "";
    }

    int compute_hash(string s) {
        int result = 0;
        for(char &c : s) {
            result = (result * BASE + (c - 'a')) % MOD;
        }
        return result;
    }

    int safe_pow(int pow) {
        int base = BASE;
        int x = 1;

        while(pow) {
            if(pow & 1) {
                x = (x * base) % MOD;
            }
            base = (base * base) % MOD;
            pow >>= 1;
        }
        return x;
    }

    bool compare_arr(string &a, int a_s, string &b, int b_s, int len) {
        for(int i = 0; i < len; ++i) {
            if(a[a_s+i] != b[b_s+i])
                return false;
        }
        return true;
    }

};