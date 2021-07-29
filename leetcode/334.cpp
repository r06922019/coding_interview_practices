class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> left_min(n, INT_MAX);
        // for(int i = 1; i < n; ++i) {
        //     left_min[i] = min(left_min[i-1], nums[i-1]);
        // }
        // vector<int> right_max(n, INT_MIN);
        // for(int i = n-2; i >= 0; --i) {
        //     right_max[i] = max(right_max[i+1], nums[i+1]);
        // }
        // for(int i = 0; i < n; ++i) {
        //     if(left_min[i] < nums[i] && nums[i] < right_max[i]) return true;
        // }

        int smallest = INT_MAX, smallest2 = INT_MAX;
        for(auto &num : nums) {
            if(num <= smallest) {
                smallest = num;
            }
            else if(num <= smallest2) {
                // num > smallest but <= smallest2
                smallest2 = num;
            }
            else {
                // smallest < smallest2 < num
                return true;
            }
        }
        return false;
    }
};