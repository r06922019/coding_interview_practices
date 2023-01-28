class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> costs(n, INT_MAX);
        costs[src] = 0;
        for (int i = 0; i < k + 1; ++i)
        {
            vector<int> new_costs = costs;
            for (auto f : flights)
            {
                int from = f[0], to = f[1], price = f[2];
                if (costs[from] != INT_MAX)
                {
                    new_costs[to] = min(costs[from] + price, new_costs[to]);
                }
            }
            costs = new_costs;
        }
        return (costs[dst] == INT_MAX) ? -1 : costs[dst];
    }
};