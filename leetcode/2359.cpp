class Solution
{
public:
    vector<int> bfs_distance(const int &start, vector<int> &edges)
    {
        vector<int> ret(edges.size(), -1);
        int steps = 0;
        queue<int> q;
        q.push(start);
        ret[start] = 0;
        while (q.size())
        {
            auto q_n = q.size();
            while (q_n--)
            {
                auto cur = q.front();
                q.pop();
                const auto nex = edges[cur];
                if (nex != -1 && ret[nex] == -1)
                {
                    ret[nex] = steps + 1;
                    q.push(nex);
                }
            }
            ++steps;
        }
        return ret;
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        auto dis1 = bfs_distance(node1, edges);
        auto dis2 = bfs_distance(node2, edges);
        int index = -1;
        for (int i = 0; i < edges.size(); ++i)
        {
            if (dis1[i] != -1 && dis2[i] != -1)
            {
                auto cur_ans = max(dis1[i], dis2[i]);
                if (index == -1 || cur_ans < max(dis1[index], dis2[index]))
                {
                    index = i;
                }
            }
        }
        return index;
    }
};