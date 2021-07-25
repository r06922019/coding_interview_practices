class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int cur_max = nums[0], cur_min = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            auto &num = nums[i];
            int from_max = cur_max * num;
            int from_min = cur_min * num;
            if(num < 0) swap(from_max, from_min);
            cur_max = max(num, from_max);
            cur_min = min(num, from_min);
            ans = max(ans, cur_max);
        }
        return ans;
    }
};