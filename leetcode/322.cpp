class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2); // -2 means unvisited
        dp[0] = 0;
        return solve(coins, amount, dp);
    }

    int solve(vector<int> &coins, int amount, vector<int> &dp) {
        if(amount < 0) return -1;
        if(dp[amount] > -2) return dp[amount];

        int ans = INT_MAX;
        for(int &coin : coins) {
            int sub_ans = solve(coins, amount-coin, dp);
            if(sub_ans >= 0)
                ans = min(ans, sub_ans + 1);
        }
        dp[amount] = (ans == INT_MAX)? -1:ans;
        return dp[amount];
    }
};

