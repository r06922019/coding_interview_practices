class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 1) return 1;
        string r(s.rbegin(), s.rend());
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0) {
                    if(s[i] == r[j]) {
                        dp[i][j] = 1;
                    }
                    else if(i != 0 || j != 0){
                        if(i == 0) dp[i][j] = dp[i][j-1];
                        else dp[i][j] = dp[i-1][j];
                    }
                }
                else {
                    if(s[i] == r[j]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else {
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};