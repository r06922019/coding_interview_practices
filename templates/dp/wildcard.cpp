class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size(), n = s.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        // for(int j = 1; j <= n; ++j) dp[0][j] = false;
        for(int i = 1; i <= m; ++i) {
            if(p[i-1] == '*') {
                dp[i][0] = dp[i-1][0];
            }
        }

        for(int i = 1; i <= m; ++i) {
            bool prev_result = dp[i-1][0];
            for(int j = 1; j <= n; ++j) {
                prev_result = prev_result || dp[i-1][j];
                if(p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    // dp[i][j] = sum(dp[i-1][0..j]);
                    dp[i][j] = prev_result;
                }
                else {
                    if(p[i-1] == s[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};