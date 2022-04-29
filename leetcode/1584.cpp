class Solution
{
public:
    int manhattan(const vector<int> &p1, const vector<int> &p2)
    {
        int ans = 0;
        for (int i = 0; i < 2; ++i)
        {
            ans += abs(p1[i] - p2[i]);
        }
        return ans;
    }

    int minCostConnectPoints(vector<vector<int> > &points)
    {
        int n = points.size();
        int total_cost = 0;
        vector<bool> included(n, false);
        vector<int> min_dist(n, 5e6);
        // do n times
        for (int i = 0; i < n; ++i)
        {
            int picked = -1;
            if (i == 0)
            {
                picked = 0;
                min_dist[0] = 0;
            }
            else
            {
                for (int j = 0; j < n; ++j)
                {
                    if (!included[j] && (picked == -1 || min_dist[j] < min_dist[picked]))
                    {
                        picked = j;
                    }
                }
            }
            included[picked] = true;
            total_cost += min_dist[picked];
            for (int j = 0; j < n; ++j)
            {
                if (!included[j])
                {
                    min_dist[j] = min(min_dist[j], manhattan(points[j], points[picked]));
                }
            }
        }
        return total_cost;
    }
};