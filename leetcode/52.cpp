class Solution {
public:
    void helper(int row, int n, unordered_set<int> &col_used,
                unordered_set<int> &diag1_used, unordered_set<int> &diag2_used,
                int &ans) {
        if(row == n) {
            ++ans;
            return ;
        }

        for(int col = 0; col < n; ++col) {
            // put queen at (row, col)
            if(col_used.find(col) != col_used.end()) continue;
            int diag1 = row + col;
            if(diag1_used.find(diag1) != diag1_used.end()) continue;
            int diag2 = row - col;
            if(diag2_used.find(diag2) != diag2_used.end()) continue;
            col_used.insert(col);
            diag1_used.insert(diag1);
            diag2_used.insert(diag2);
            helper(row+1, n, col_used, diag1_used, diag2_used, ans);
            col_used.erase(col);
            diag1_used.erase(diag1);
            diag2_used.erase(diag2);
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        unordered_set<int> col_used, diag1_used, diag2_used;
        helper(0, n, col_used, diag1_used, diag2_used, ans);
        return ans;
    }
};