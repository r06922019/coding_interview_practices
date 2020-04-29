class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> heights(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    ++heights[j];
                }
                else {
                    heights[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> h_stack;
        if(heights.back() > 0)
            heights.push_back(0);

        int ans = 0;
        for(int i = 0; i < heights.size(); ++i) {
            int &h = heights[i], index = i;
            while(h_stack.size() && h < h_stack.top().second) {
                pair<int, int> top = h_stack.top();
                h_stack.pop();
                ans = max(ans, (i-top.first) * top.second);
                index = top.first;
            }
            h_stack.push({index, h});
        }
        return ans;
    }
};