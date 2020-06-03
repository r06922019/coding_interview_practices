
/*
// bfs
class Pos {
public:
    int i, j;

    Pos(int _i, int _j) {
        i = _i;
        j = _j;
    }

    vector<Pos> get_valid_neighbors(vector<vector<int>> &grid) {
        vector<Pos> ret;
        if(is_valid(grid, i-1, j))
            ret.push_back(Pos(i-1, j));
        if(is_valid(grid, i+1, j))
            ret.push_back(Pos(i+1, j));
        if(is_valid(grid, i, j-1))
            ret.push_back(Pos(i, j-1));
        if(is_valid(grid, i, j+1))
            ret.push_back(Pos(i, j+1));
        return ret;
    }

    static bool is_valid(vector<vector<int>> &grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 1)
            return false;
        return true;
    }

    bool operator==(const Pos &other) {
        return (i == other.i) && (j == other.j);
    }
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> grid_3x3(3*m, vector<int>(3*n, 1));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                fill_in(grid_3x3, i, j, grid[i][j]);
            }
        }
        return bfs(grid_3x3, 3*m, 3*n);
    }

    void fill_in(vector<vector<int>> &grid, int i, int j, int type) {
        i = 3*i+1;
        j = 3*j+1;
        grid[i][j] = 0;

        if(type == 1) {
            grid[i][j-1] = grid[i][j+1] = 0;
        }
        else if(type == 2) {
            grid[i-1][j] = grid[i+1][j] = 0;
        }
        else if(type == 3) {
            grid[i][j-1] = grid[i+1][j] = 0;
        }
        else if(type == 4) {
            grid[i][j+1] = grid[i+1][j] = 0;
        }
        else if(type == 5) {
            grid[i][j-1] = grid[i-1][j] = 0;
        }
        else if(type == 6) {
            grid[i][j+1] = grid[i-1][j] = 0;
        }
        return ;
    }

    void visit(vector<vector<int>> &grid, Pos &p) {
        grid[p.i][p.j] = 1;
    }

    bool bfs(vector<vector<int>> &grid, int m, int n) {
        Pos start(1, 1), target(m-2, n-2);

        queue<Pos> q;
        q.push(start);
        visit(grid, start);

        while(q.size()) {
            Pos cur = q.front();
            q.pop();
            if(cur == target) return true;

            for(Pos &next : cur.get_valid_neighbors(grid)) {
                q.push(next);
                visit(grid, next);
            }
        }
        return false;
    }
};
*/