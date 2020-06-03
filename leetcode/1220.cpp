class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1000000000+7;
        vector<long long int> dp_a(n+1, 0);
        vector<long long int> dp_e(n+1, 0);
        vector<long long int> dp_i(n+1, 0);
        vector<long long int> dp_o(n+1, 0);
        vector<long long int> dp_u(n+1, 0);
        dp_a[1] = dp_e[1] = dp_i[1] = dp_o[1] = dp_u[1] = 1;

        for(int i = 2; i <= n; ++i) {
            dp_a[i] = (dp_e[i-1] + dp_i[i-1] + dp_u[i-1]) % MOD;
            dp_e[i] = (dp_a[i-1] + dp_i[i-1]) % MOD;
            dp_i[i] = (dp_e[i-1] + dp_o[i-1]) % MOD;
            dp_o[i] = (dp_i[i-1]) % MOD;
            dp_u[i] = (dp_i[i-1] + dp_o[i-1]) % MOD;
        }
        return (dp_a[n] + dp_e[n] + dp_i[n] + dp_o[n] + dp_u[n]) % MOD;
    }
};