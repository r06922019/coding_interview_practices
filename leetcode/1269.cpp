class Solution {
public:
    int MOD = 1e9 + 7;
    // int safe_add(int a, int b) {
    //  return (a % MOD + b % MOD) % MOD;
    // }

    int numWays(int steps, int arrLen) {
        int max_index = min(arrLen-1, steps/2+1);
        vector<vector<int>> dp(steps+1, vector<int>(max_index+1, 0));
        // dp[i][j] represents way to move to index j at steps i
        dp[0][0] = 1;
        for(int i = 1; i <= steps; ++i) {
            for(int j = 0; j <= max_index; ++j) {
                dp[i][j] = dp[i-1][j]; // stay is always valid
                if(j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
                if(j < max_index) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
                }
            }
        }
        return dp[steps][0];
    }
};
