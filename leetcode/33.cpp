class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            // printf("l = %d, mid = %d, r = %d\n", l, mid, r);
            if(nums[l] <= nums[mid]) { // l~mid is sorted
                if(nums[l] <= target && target <= nums[mid])
                    r = mid;
                else
                    l = mid+1;
            }
            else { // mid+1~r is sorted
                if(nums[mid] < target && target <= nums[r])
                    l = mid+1;
                else
                    r = mid;
            }
        }
        // printf("l = %d, r = %d\n", l, r);
        if(nums[l] != target) return -1;
        return l;
    }
};
