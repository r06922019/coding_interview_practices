class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (auto s : stones)
            pq.push(s);

        while (pq.size() >= 2)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a != b)
            {
                pq.push(max(a, b) - min(a, b));
            }
        }
        return (pq.size()) ? pq.top() : 0;
    }
};