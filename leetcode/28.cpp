class Solution {
public:

    const long long BASE = 3;
    const int MOD = 1e9+7;

    int add(const int a, const int b) {
        int tmp = ((a % MOD) + (b % MOD)) % MOD;
        return (tmp < 0)? tmp+MOD:tmp;
    }

    int mul(const int a, const int b) {
        long long tmp = a % MOD;
        tmp = tmp * (b % MOD);
        tmp %= MOD;
        return (tmp < 0)? tmp+MOD:tmp;
    }

    int rehash(string s, int l, int r, int highest_mul, int old_hash) {
        int tmp = add(old_hash, MOD);
        tmp = add(tmp, mul(s[l], -highest_mul));
        tmp = add(mul(tmp, BASE), s[r]);
        return tmp;
    }

    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack.size() < needle.size()) return -1;
        int m = haystack.size(), n = needle.size();
        int needle_hash = 0, highest_mul = 1, haystack_hash = 0;
        for(int i = 0; i < n; ++i) {
            needle_hash = add(mul(needle_hash, BASE), needle[i]);
            haystack_hash = add(mul(haystack_hash, BASE), haystack[i]);
            if(i > 0)
                highest_mul = mul(highest_mul, BASE);
        }

        if(haystack_hash == needle_hash && haystack.substr(0, n) == needle) {
            return 0;
        }

        for(int i = n; i < m; ++i) {
            haystack_hash = rehash(haystack, i-n, i, highest_mul, haystack_hash);
            if(haystack_hash == needle_hash && haystack.substr(i-n+1, n) == needle) {
                return i-n+1;
            }
        }

        return -1;
    }
};