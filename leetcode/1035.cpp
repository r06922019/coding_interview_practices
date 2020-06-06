class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; ++i) {
            int &a = A[i-1];
            for(int j = 1; j <= n; ++j) {
                int &b = B[j-1];
                if(a == b) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};