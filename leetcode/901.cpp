class Item
{
public:
    int value = 0, count = 0;
    Item(int _v, int _c)
    {
        count = _c;
        value = _v;
    }
};

class StockSpanner
{
public:
    stack<Item> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int count = 1;
        while (st.size() && price >= st.top().value)
        {
            count += st.top().count;
            st.pop();
        }
        st.push(Item(price, count));
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */