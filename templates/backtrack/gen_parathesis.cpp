class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<char> buf;
        helper(n, n, buf, ans);
        return ans;
    }

    void helper(int l, int r, vector<char> &buf, vector<string> &ans) {
        if(l == 0 && r == 0) {
            ans.push_back(string(buf.begin(), buf.end()));
            return;
        }

        if(l > 0) {
            buf.push_back('(');
            helper(l-1, r, buf, ans);
            buf.pop_back();
        }

        if(r > 0 && r > l) {
            buf.push_back(')');
            helper(l, r-1, buf, ans);
            buf.pop_back();
        }
    }
};