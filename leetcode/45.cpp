class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        /*
        vector<int> steps(n, INT_MAX);
        steps[0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= nums[i] && i+j < n; ++j) {
                steps[i+j] = min(steps[i+j], steps[i]+1);
            }
        }
        return steps.back();
        */
        int steps = 0;
        int next_jump_max = 0, cur_max = 0;
        for(int i = 0; i < n; ++i) {
            if(i > cur_max) {
                ++steps;
                cur_max = next_jump_max;
            }
            next_jump_max = max(next_jump_max, i + nums[i]);
        }
        return steps;
    }
};