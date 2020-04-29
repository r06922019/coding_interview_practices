class Solution {
public:
    int trap(vector<int>& heights) {
        if(heights.size() < 3) {
            return 0;
        }

        int ans = 0, n = heights.size();
        vector<int> left_max = heights, right_max = heights;
        for(int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i], left_max[i-1]);
        }

        for(int i = n-1-1; i >= 0; --i) {
            right_max[i] = max(right_max[i], right_max[i+1]);
        }

        for(int i = 1; i < n-1; ++i) {
            ans += min(left_max[i], right_max[i]) - heights[i];
        }
        return ans;
    }
};