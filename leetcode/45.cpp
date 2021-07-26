class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, INT_MAX);
        steps[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= nums[i] && i+j < n; ++j) {
                steps[i+j] = min(steps[i+j], steps[i]+1);
            }
        }
        return steps.back();
    }
};