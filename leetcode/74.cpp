class Solution
{
public:
    int binary_search(int l, int r, const std::function<bool(int)> &func)
    {
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (func(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size();
        const auto row_checker = [&matrix, &target](int index)
        {
            return matrix[index].back() >= target;
        };
        int row_index = binary_search(0, m, row_checker);
        if (row_index == m)
            return false;

        const auto &vec = matrix[row_index];
        int n = vec.size();
        const auto col_checker = [&vec, &target](const int index)
        {
            return vec[index] >= target;
        };
        int col_index = binary_search(0, n, col_checker);
        if (col_index == n)
            return false;
        return vec[col_index] == target;
    }
};