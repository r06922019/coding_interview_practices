class Solution {
public:
    int get_group(vector<int>& nums, int target, int l, int r) {
        if(target > nums[r]) return 0;
        return 1;
    }

    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            // by skipping the repeated values
            // we ensure nums[mid] will not == nums[l] && nums[r]
            // unless there are only 2 elements left,
            // which doesn't matter anyway in this case
            while(l < r && nums[l] == nums[l+1]) ++l;
            while(l < r && nums[r] == nums[r-1]) --r;
            // then we continue with the original logic,
            // first we classify the group of mid and target
            // then choose if we reverse the logic due to they being in different groups
            int mid = l + (r-l)/2;
            int target_group = get_group(nums, target, l, r);
            int mid_group = get_group(nums, nums[mid], l, r);
            // printf("%d, %d, %d\n", l, mid, r);
            if((target_group == mid_group && target <= nums[mid]) ||
               (target_group != mid_group && target > nums[mid])) {
                // same group then normal logic
                // different group then reversed logic
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return (l < nums.size() && nums[l] == target);
    }
};
