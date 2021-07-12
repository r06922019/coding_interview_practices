class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int cur_sum = 0, l = 0, r = 0;
        while(r < nums.size()) {
            cur_sum += nums[r];
            ++r;
            while(cur_sum >= target && l < r) {
                ans = min(ans, r-l);
                cur_sum -= nums[l];
                ++l;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};