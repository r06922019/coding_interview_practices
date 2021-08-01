class Solution {
public:

    int get_distance_to_median(vector<int> &houses, int start_index, int end_index) {
        int middle_index = start_index + (end_index-start_index)/2;
        int the_median = houses[middle_index];
        int ans = 0;
        for(int i = start_index; i < end_index; ++i) {
            ans += abs(houses[i] - the_median);
        }
        return ans;
    }

    int helper(vector<int> &houses, int index, int k, vector<vector<int>> &dp) {
        if(k == 1) {
            dp[index][k] = get_distance_to_median(houses, index, houses.size());
            return dp[index][k];
        }
        if(houses.size() - index <= k) return 0;
        if(dp[index][k] != -1) return dp[index][k];

        int ans = INT_MAX;
        for(int i = index, n = houses.size(); (i + k - 1) < n; ++i) {
            int tmp = get_distance_to_median(houses, index, i+1) + helper(houses, i+1, k-1, dp);
            ans = min(ans, tmp);
        }
        dp[index][k] = ans;
        return ans;
    }

    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        sort(houses.begin(), houses.end());
        return helper(houses, 0, k, dp);
    }
};