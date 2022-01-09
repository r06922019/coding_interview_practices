// Minimum Swaps to Group All 1's Together II
// A swap is defined as taking two distinct positions in an array and swapping the values in them.
// A circular array is defined as an array where we consider the first element and the last element to be adjacent.
// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> nums_repeat = nums;
        for(auto num : nums) {
            nums_repeat.push_back(num);
        }
        vector<int> acc = {0};
        for(auto num : nums_repeat) {
            acc.push_back(acc.back() + num);
        }

        int n = nums.size(), ans = INT_MAX;
        int ones = acc[n];
        for(int i = ones; i < nums_repeat.size(); ++i) {
            ans = min(ans, ones - (acc[i] - acc[i-ones]));
        }
        
        return ans;
    }
};
