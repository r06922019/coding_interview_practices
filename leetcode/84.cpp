class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> h_stack;
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