class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        for(int round = 0; round < (m+n-1); ++round) {
            // printf("round %d\n", round);
            if(round % 2 == 0) {
                if(round < m) {
                    for(int i = round; i >= 0 && (round-i) < n; --i) {
                        // printf("pushing %d\n", mat[i][round-i]);
                        ans.push_back(mat[i][round-i]);
                    }
                }
                else {
                    for(int i = m-1; i >= 0 && (round-i) < n; --i) {
                        // printf("pushing %d\n", mat[i][round-i]);
                        ans.push_back(mat[i][round-i]);
                    }
                }
            }
            else {
                if(round < n) {
                    for(int j = round; j >= 0 && (round-j) < m; --j) {
                        // printf("pushing %d\n", (mat[round-j][j]));
                        ans.push_back(mat[round-j][j]);
                    }
                }
                else {
                    for(int j = n-1; j >= 0 && (round-j) < m; --j) {
                        // printf("pushing %d\n", (mat[round-j][j]));
                        ans.push_back(mat[round-j][j]);
                    }
                }
            }
        }
        return ans;
    }
};