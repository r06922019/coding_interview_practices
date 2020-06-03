class Solution {
public:
    int numTrees(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;
        // n > 1

        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int left = 0; left < i; ++left) {
                dp[i] += dp[left] * dp[i-1-left]; // left, root, right
            }
        }
        return dp[n];
    }
};