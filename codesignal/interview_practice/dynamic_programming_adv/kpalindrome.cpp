bool kpalindrome(string s, int k) {
    string r(s.rbegin(), s.rend());
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(s[i] == r[j]) {
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[n][n] + k >= s.size();
}
