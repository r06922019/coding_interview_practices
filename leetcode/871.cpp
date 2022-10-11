class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int> > &stations)
    {
        priority_queue<int> pq;
        int max_reach = startFuel, cnt = 0, i = 0;
        while (max_reach < target)
        {
            while (i < stations.size() && stations[i][0] <= max_reach)
            {
                pq.push(stations[i][1]);
                ++i;
            }
            if (pq.size() == 0)
            {
                return -1;
            }
            max_reach += pq.top();
            pq.pop();
            ++cnt;
        }
        return cnt;
    }
};