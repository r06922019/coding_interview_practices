    int exp(const int &base, int e) {
        int ans = 0;
        long long cur = base % MOD;
        while(e) {
            if(e & 1) {
                ans += cur;
            }
            e = e >> 1;
            cur = (cur * cur) % MOD;
        }
        return ans;
    }