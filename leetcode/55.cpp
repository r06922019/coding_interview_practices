class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_len = 0;
        for(int i = 0; i < nums.size() && max_len >= i; ++i) {
            max_len = max(i+nums[i], max_len);
        }
        return max_len >= nums.size()-1;
    }
};