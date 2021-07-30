class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        for(int i = 0; i <= r; ++i) {
            if(nums[i] == 0) {
                swap(nums[l], nums[i]);
                ++l;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
                --r;
                --i;
            }
        }
    }
};