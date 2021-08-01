class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int lcs_len = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(word1[i] == word2[j]) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    lcs_len = max(lcs_len, dp[i][j]);
                }
                else {
                    if(i > 0)
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    if(j > 0)
                        dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return m + n - lcs_len - lcs_len;
    }
};