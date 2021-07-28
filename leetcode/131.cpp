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

    void helper(string &s, int index,
                vector<vector<bool>> &palin,
                vector<string> &buf,
                vector<vector<string>> &ans) {
        if(index == s.size()) {
            ans.push_back(buf);
            return ;
        }

        for(int j = index; j < s.size(); ++j) {
            if(palin[index][j]) {
                buf.push_back(s.substr(index, j-index+1));
                helper(s, j+1, palin, buf, ans);
                buf.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                palin[i][j] = is_palin(s, i, j);
            }
        }

        vector<string> buf;
        vector<vector<string>> ans;
        helper(s, 0, palin, buf, ans);
        return ans;
    }
};