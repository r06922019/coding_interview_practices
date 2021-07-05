    int mul(const int &base, int mul) {
        int ans = 0;
        long long cur = base % MOD;
        while(mul) {
            if(mul & 1) {
                ans += cur;
            }
            mul = mul >> 1;
            cur = (cur * 2) % MOD;
        }
        return ans;
    }