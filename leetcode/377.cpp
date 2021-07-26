class Solution {
public:
    unordered_map<int, int> dp = {{0,1}};
    int combinationSum4(vector<int>& nums, int target) {
        if(target < 0) return 0;
        if(dp.find(target) != dp.end()) return dp[target];
        int ans = 0;
        for(auto &num : nums) {
            /*
            f(nums, 4) = sum([f(nums, 4-nums[0]), f(nums, 4-nums[1]),
                            ...f(nums, 4-nums[i]))
            */
            ans += combinationSum4(nums, target-num);
        }
        dp[target] = ans;
        return ans;
    }
};