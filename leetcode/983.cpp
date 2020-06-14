class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        vector<int> dp(len+1, -1); // -1 => not visited
        unordered_map<int, int> costs_dict = {{1, costs[0]}, {7, costs[1]}, {30, costs[2]}};
        return solve(len, days, costs_dict, dp);
    }

    int solve(int len, vector<int> &days, unordered_map<int, int> &costs_dict,
              vector<int> &dp) {
        if(len <= 0) return 0;
        if(dp[len] > -1) return dp[len];

        int ans = INT_MAX, cur_day = days[len-1];
        for(auto &it : costs_dict) {
            int duration = it.first, cost = it.second;
            int prev_len = len;
            while(prev_len > 0 && cur_day - days[prev_len-1] < duration)
                --prev_len;
            ans = min(ans, cost + solve(prev_len, days, costs_dict, dp));
        }
        dp[len] = ans;
        return dp[len];
    }
};
