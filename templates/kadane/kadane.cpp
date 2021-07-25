class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], cur_sum = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int &num = nums[i];
            cur_sum = max(num, cur_sum + num);
            ans = max(ans, cur_sum);
        }
        return ans;
    }
};