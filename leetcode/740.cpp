class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(1e4+1, 0);
        int max_num = 0;
        for(auto &num : nums) {
            count[num] += num;
            max_num = max(max_num, num);
        }

        vector<int> dp(max_num+1, 0);
        dp[1] = count[1];
        for(int i = 2; i <= max_num; ++i) {
            dp[i] = max(dp[i-2] + count[i], dp[i-1]);
        }
        return dp[max_num];
    }
};