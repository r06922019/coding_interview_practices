class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_square_side = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sides(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    sides[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(sides[i][j] == 1) {
                    if(i > 0 && j > 0)
                        sides[i][j] += min(sides[i-1][j-1], min(sides[i-1][j], sides[i][j-1]));
                    max_square_side = max(max_square_side, sides[i][j]);
                }
            }
        }
        return max_square_side * max_square_side;
    }
};