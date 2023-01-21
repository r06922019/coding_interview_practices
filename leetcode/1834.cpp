class Item
{
public:
    int t, i;
    Item(int _t, int _i)
    {
        t = _t, i = _i;
    }
};
class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        auto cmp = [](const Item &a, const Item &b)
        {
            if (a.t > b.t)
                return true;
            if (a.t == b.t && a.i > b.i)
                return true;
            return false;
        };
        priority_queue<Item, vector<Item>, decltype(cmp)> pq_t(cmp), pq_q(cmp);
        for (int i = 0; i < tasks.size(); ++i)
        {
            pq_t.push(Item(tasks[i][0], i));
        }
        long long cur_time = 0;
        vector<int> ans;
        while (pq_t.size() || pq_q.size())
        {
            if (pq_t.top().t > cur_time && pq_q.size() == 0)
                cur_time = pq_t.top().t;

            while (pq_t.size() && pq_t.top().t <= cur_time)
            {
                auto cur = pq_t.top();
                pq_t.pop();
                auto i = cur.i;
                pq_q.push(Item(tasks[i][1], i));
            }
            if (pq_q.size())
            {
                auto task = pq_q.top();
                pq_q.pop();
                auto t = task.t, i = task.i;
                cur_time += t;
                ans.push_back(i);
            }
        }
        return ans;
    }
};