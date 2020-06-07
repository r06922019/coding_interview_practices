class Solution {
public:
    int trap(vector<int>& heights) {
        // find left right max
        int cur_max = 0, n = heights.size();
        vector<int> left, right(n, 0);
        for(int &h : heights) {
            left.push_back(cur_max);
            cur_max = max(cur_max, h);
        }

        cur_max = 0;
        for(int i = n-1; i>= 0; --i) {
            right[i] = cur_max;
            cur_max = max(cur_max, heights[i]);
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += max(0, min(left[i], right[i]) - heights[i]);
        }
        return ans;
    }
};