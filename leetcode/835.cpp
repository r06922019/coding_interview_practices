class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        vector<vector<int>> pairs1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (img1[i][j])
                    pairs1.push_back({i, j});
            }
        }

        int ans = 0;
        for (int d_i = -n + 1; d_i < n; ++d_i)
        {
            for (int d_j = -n + 1; d_j < n; ++d_j)
            {
                int cur_ans = 0;
                for (auto p1 : pairs1)
                {
                    const int i = p1[0] + d_i;
                    const int j = p1[1] + d_j;
                    if (i >= 0 && i < n && j >= 0 && j < n && img2[i][j])
                    {
                        ++cur_ans;
                    }
                }
                ans = max(ans, cur_ans);
            }
        }
        return ans;
    }
};