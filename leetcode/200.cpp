class Solution {
public:
    vector<vector<int>> dirs = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    bool is_valid(vector<vector<char>>& grid, vector<int> &cur,
                  vector<int> &dir, vector<int> &new_pos) {
        new_pos[0] = cur[0] + dir[0];
        new_pos[1] = cur[1] + dir[1];
        if(new_pos[0] < 0 || new_pos[1] < 0) return false;
        if(new_pos[0] >= grid.size() || new_pos[1] >= grid[0].size()) return false;
        return grid[new_pos[0]][new_pos[1]] == '1';
    }

    int bfs(vector<vector<char>>& grid, vector<int> start) {
        queue<vector<int>> q;
        vector<int> new_pos = {0,0};
        q.push(start);
        grid[start[0]][start[1]] = '0';
        while(q.size()) {
            vector<int> cur = q.front();
            q.pop();
            for(auto &dir : dirs) {
                if(is_valid(grid, cur, dir, new_pos)) {
                    q.push(new_pos);
                    grid[new_pos[0]][new_pos[1]] = '0';
                }
            }
        }
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    count += bfs(grid, {i,j});
                }
            }
        }
        return count;
    }
};