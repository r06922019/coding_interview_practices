class Item {
public:
    int index, price;
    Item () {
        index = price = -1;
    }
    Item(int _i, int _p) {
        index = _i;
        price = _p;
    }

};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        stack<Item> st;
        for(int i = 0; i < n; ++i) {
            int &p = prices[i];
            while(st.size() && st.top().price >= p) {
                int &index = st.top().index;
                ans[index] -= p;
                st.pop();
            }
            st.push(Item(i, p));
        }

        return ans;
    }
};