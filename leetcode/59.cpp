enum class Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        unordered_map<Direction, vector<int>> dir_to_vec = {
            {Direction::RIGHT, {0, 1}},
            {Direction::DOWN, {1,0}},
            {Direction::LEFT, {0, -1}},
            {Direction::UP, {-1,0}},
        };

        vector<vector<int>> ans(n, vector<int>(n, 0));
        Direction cur_dir = Direction::RIGHT;
        vector<int> cur = {0,0}, dir = dir_to_vec[cur_dir];
        int i_min = 1, i_max = n-1, j_min = 0, j_max = n-1;
        for(int num = 1, total_size = n*n; num <= total_size; ++num) {
            ans[cur[0]][cur[1]] = num;
            if(cur_dir == Direction::RIGHT) {
                if(cur[1] == j_max) {
                    cur_dir = Direction::DOWN;
                    --j_max;
                    dir = dir_to_vec[cur_dir];
                }
            }
            else if(cur_dir == Direction::DOWN) {
                if(cur[0] == i_max) {
                    cur_dir = Direction::LEFT;
                    --i_max;
                    dir = dir_to_vec[cur_dir];
                }
            }
            else if(cur_dir == Direction::LEFT) {
                if(cur[1] == j_min) {
                    cur_dir = Direction::UP;
                    ++j_min;
                    dir = dir_to_vec[cur_dir];
                }
            }
            else if(cur_dir == Direction::UP) {
                if(cur[0] == i_min) {
                    cur_dir = Direction::RIGHT;
                    ++i_min;
                    dir = dir_to_vec[cur_dir];
                }
            }
            cur[0] += dir[0];
            cur[1] += dir[1];
        }
        return ans;
    }
};