int paintHouses(vector<vector<int>> cost) {
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
    // dp[i][j] is the accumulated cost where the house i is painted j
    dp[0] = cost[0];
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                if(k == j) continue;
                dp[i][j] = min(dp[i-1][k] + cost[i][j], dp[i][j]);
            }
        }
    }
    return *min_element(dp.back().begin(), dp.back().end());
}
