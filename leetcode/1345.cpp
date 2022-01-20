class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        unordered_map<int, vector<int> > val_to_index;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            val_to_index[arr[i]].push_back(i);

        int steps = 0;
        queue<int> q;
        q.push(0);
        vector<bool> visited(arr.size(), false);
        while (q.size())
        {
            n = q.size();
            while (n--)
            {
                int cur = q.front();
                q.pop();
                if (cur == arr.size() - 1)
                    return steps;
                auto cands = val_to_index[arr[cur]];
                val_to_index.erase(arr[cur]);
                for (auto x : {cur - 1, cur + 1})
                    if (x >= 0 && x < arr.size() && !visited[x])
                        cands.push_back(x);
                for (auto &x : cands)
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
            ++steps;
        }

        return -1;
    }
};