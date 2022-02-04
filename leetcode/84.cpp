class Item
{
public:
    int h, i;
    Item(int h_, int i_)
    {
        i = i_;
        h = h_;
    }
};

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        int ans = 0;
        stack<Item> st;
        for (int i = 0; i < heights.size(); ++i)
        {
            const auto &h = heights[i];
            int index = i;
            while (st.size() && st.top().h >= h)
            {
                ans = max(ans, (i - st.top().i) * st.top().h);
                index = st.top().i;
                st.pop();
            }
            st.push(Item(h, index));
        }
        return ans;
    }
};