class Solution {
public:
    int get_group(vector<int> &nums, int l, int r, int x) {
        if(x > nums[r]) return 0;
        return 1;
    }

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(get_group(nums, l, r, nums[mid]) == 0) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
    }
};