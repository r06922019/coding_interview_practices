class Solution {
public:
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

    int pow2(int x) {
        int num = 1;
        int base = 2;
        while(x) {
            if(x & 1) {
                num = mul(num, base);
            }
            x >>= 1;
            base = mul(base, base);
        }
        return num;
    }

    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        // len <= n that ends at x
        int zeros = 0, ones = 0, twos = 0;
        for(auto &num : nums) {
            if(num == 0) {
                ++zeros;
            }
            else if(num == 1) {
                // ones += ones + 2**zeros-1
                ones = add(ones, add(ones, add(pow2(zeros), -1)));
            }
            else {
                // twos += ones + twos
                twos = add(twos, add(twos, ones));
            }
        }
        return twos;
    }
};