class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even = 0, odd = 0;
        for (const auto& num : nums) {
            if (num % 2 == 0) {
                ++even;
            } else {
                ++odd;
            }
        }
        vector<int> ans;
        while (even-- > 0) {
            ans.push_back(0);
        }
        while (odd-- > 0) {
            ans.push_back(1);
        }
        return ans;
    }
};
