class Solution {
public:
    int binary_search0(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.size() && (target < nums.front() || nums.back() < target)) return -1;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(target <= nums[mid]) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        if(nums[l] == target) return l;
        return -1;
    }

    int binary_search1(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.size() && (target < nums.front() || nums.back() < target)) return -1;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l+1)/2;
            if(target < nums[mid]) {
                r = mid-1;
            }
            else {
                l = mid;
            }
        }
        if(nums[l] == target) return l;
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = binary_search0(nums, target);
        ans[1] = binary_search1(nums, target);
        return ans;
    }
};