enum class Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int total_size = m*n;
        vector<int> ans;
        Direction cur_dir = Direction::RIGHT;
        unordered_map<Direction, vector<int>> dir_to_vec = {
            {Direction::RIGHT, {0,1}},
            {Direction::DOWN, {1,0}},
            {Direction::LEFT, {0,-1}},
            {Direction::UP, {-1,0}},
        };
        vector<int> cur{0,0}, dir{0,1};
        int i_min = 1, i_max = m-1, j_min = 0, j_max = n-1;
        while(total_size--) {
            ans.push_back(matrix[cur[0]][cur[1]]);
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
            else { // UP
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