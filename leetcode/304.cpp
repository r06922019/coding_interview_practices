class NumMatrix
{
public:
    vector<vector<int> > matrix;
    NumMatrix(vector<vector<int> > &mat) : matrix(mat.size() + 1, vector<int>(mat[0].size() + 1, 0))
    {
        int m = mat.size(), n = mat[0].size();
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                matrix[i][j] = mat[i - 1][j - 1] + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        ++row2, ++col2;
        return matrix[row2][col2] - matrix[row1][col2] - matrix[row2][col1] + matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */