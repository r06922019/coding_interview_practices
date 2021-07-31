class Solution {
public:

    vector<vector<int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool is_valid(vector<vector<int>>& matrix,
            int i, int j) {
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size();
    }

    int dfs(vector<vector<int>>& matrix,
            int i, int j, vector<vector<int>> &visited) {
        if(visited[i][j] > 0) return visited[i][j];

        visited[i][j] = 1;
        for(auto &dir : dirs) {
            int di = dir[0], dj = dir[1];
            if(is_valid(matrix, i+di, j+dj) && matrix[i][j] < matrix[i+di][j+dj]) {
                visited[i][j] = max(visited[i][j], 1 + dfs(matrix, i+di, j+dj, visited));
            }
        }
        return visited[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visited[i][j] < 0) {
                    dfs(matrix, i, j, visited);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ans = max(ans, visited[i][j]);
            }
        }
        return ans;
    }
};