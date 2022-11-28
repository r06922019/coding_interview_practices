class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> lost;
        for (auto m : matches)
        {
            const auto winner = m[0], loser = m[1];
            lost[winner] += 0;
            lost[loser] += 1;
        }
        vector<vector<int>> ans(2, vector<int>());
        for (auto it : lost)
        {
            const auto player = it.first, count = it.second;
            if (count <= 1)
                ans[count].push_back(player);
        }
        for (int i = 0; i <= 1; ++i)
        {
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};