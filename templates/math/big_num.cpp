    const int MOD = 1e9+7;
    int mod(int x) {
        x %= MOD;
        if(x < 0) x += MOD;
        return x;
    }

    int mod(long long x) {
        x %= MOD;
        if(x < 0) x += MOD;
        return x;
    }

    int add(int a, int b) {
        return mod(mod(a) + mod(b));
    }

    int mul(int a, int b) {
        long long tmp = a;
        tmp *= mod(b);
        return mod(tmp);
    }
