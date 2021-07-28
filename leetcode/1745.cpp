class Solution {
public:

    bool is_palin(string &s, int l, int r) {
        if(l < 0 || r >= s.size() || l > r) return false;
        while(l < r) {
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                palin[i][j] = is_palin(s, i, j);
            }
        }
        for(int l = 1; l < n-1; ++l) {
            for(int r = l; r < n-1; ++r) {
                if(palin[0][l-1] && palin[l][r] && palin[r+1][n-1])
                    return true;
            }
        }
        return false;
    }
};