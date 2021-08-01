class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size(), max_lcs_sum = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // max ascii sum
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(s1[i] == s2[j]) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = s1[i];
                    }
                    else {
                        dp[i][j] = dp[i-1][j-1] + s1[i];
                    }
                    max_lcs_sum = max(max_lcs_sum, dp[i][j]);
                }
                else {
                    if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        int ans = 0;
        for(auto &c : s1) {
            ans += (int)c;
        }
        for(auto &c : s2) {
            ans += (int)c;
        }
        return ans - max_lcs_sum - max_lcs_sum;
    }
};