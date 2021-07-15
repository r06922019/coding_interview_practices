class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(mat[i][j])
                    mat[i][j] = min(mat[i][j-1], mat[i-1][j]) + 1;
            }
        }
        for(int i = m-2; i >= 0; --i) {
            for(int j = n-2; j >= 0; --j) {
                if(mat[i][j])
                    mat[i][j] = min(mat[i][j+1], mat[i+1][j]) + 1;
            }
        }
        return mat;
    }
};