// bfs from zeros

// dp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j]) {
                    mat[i][j] = INT_MAX;
                    if(j-1 >= 0 && mat[i][j-1] < INT_MAX)
                        mat[i][j] = min(mat[i][j], mat[i][j-1] + 1);
                    if(i-1 >= 0 && mat[i-1][j] < INT_MAX)
                        mat[i][j] = min(mat[i][j], mat[i-1][j] + 1);
                }
            }
        }
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(mat[i][j]) {
                    if(j+1 < n && mat[i][j+1] < INT_MAX)
                        mat[i][j] = min(mat[i][j], mat[i][j+1] + 1);
                    if(i+1 < m && mat[i+1][j] < INT_MAX)
                        mat[i][j] = min(mat[i][j], mat[i+1][j] + 1);
                }
            }
        }
        return mat;
    }
};