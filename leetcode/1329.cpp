class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m == 0) return mat;
        int n = mat[0].size();
        if(n == 0) return mat;
        vector<pair<int, int>> starts;
        for(int i = 0; i < m; ++i) {
            starts.push_back({i,0});
        }
        for(int j = 1; j < n; ++j) {
            starts.push_back({0, j});
        }
        for(auto &start:starts) {
            vector<int> tmp;
            for(int i = start.first, j = start.second;
                i < m && j < n; ++i, ++j) {
                tmp.push_back(mat[i][j]);
            }
            sort(tmp.begin(), tmp.end());
            for(int i = start.first, j = start.second, index = 0;
                index < tmp.size(); ++i, ++j, ++index) {
                mat[i][j] = tmp[index];
            }
        }
        return mat;
    }
};