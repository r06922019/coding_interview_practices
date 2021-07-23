class Solution {
public:
    int get_group(vector<int>& nums, int target, int l, int r) {
        if(target > nums[r]) return 0;
        return 1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            int target_group = get_group(nums, target, l, r);
            int mid_group = get_group(nums, nums[mid], l, r);
            // printf("%d, %d, %d\n", l, mid, r);
            if((target_group == mid_group && target <= nums[mid]) ||
               (target_group != mid_group && target > nums[mid])) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        if(nums[l] != target) return -1;
        return l;
    }
};