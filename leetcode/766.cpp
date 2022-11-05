class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, int> seen;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                const int k = i - j;
                if (seen.find(k) != seen.end() && seen[k] != matrix[i][j])
                    return false;
                seen[k] = matrix[i][j];
            }
        }
        return true;
    }
};