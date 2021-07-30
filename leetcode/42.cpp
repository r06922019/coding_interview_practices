class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max = height;
        for(int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i], left_max[i-1]);
        }
        vector<int> right_max = height;
        for(int i = n-2; i >= 0; --i) {
            right_max[i] = max(right_max[i], right_max[i+1]);
        }
        int ans = 0;
        for(int i = 1; i < n-1; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};