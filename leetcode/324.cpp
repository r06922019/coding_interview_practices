class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int index = 0, n = nums.size();
        vector<int> nums1 = nums;
        for(int i = 1; i < n; i += 2, ++index) {
            nums1[i] = nums[index];
        }
        for(int i = 0; i < n; i += 2, ++index) {
            nums1[i] = nums[index];
        }
        nums = nums1;
    }
};