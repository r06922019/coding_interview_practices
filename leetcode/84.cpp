class Item {
public:
    int index, height;
    Item(int _i, int _h) {
        index = _i;
        height = _h;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<Item> s;
        heights.push_back(0);
        int n = heights.size(), ans = 0;
        for(int i = 0; i < n; ++i) {
            auto &h = heights[i];
            int index = i;
            while(s.size() && s.top().height >= h) {
                int prev_index = s.top().index;
                index = prev_index;
                int height = s.top().height;
                ans = max(ans, (i - prev_index) * height);
                s.pop();
            }
            s.push(Item(index, h));
        }
        return ans;
    }
};