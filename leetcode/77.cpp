class Solution
{
public:
    void helper(const int start,
                const int n,
                const int k,
                vector<int> &buf,
                vector<vector<int>> &ans)
    {
        if (buf.size() >= k)
        {
            ans.push_back(buf);
            return;
        }
        for (int i = start; i < n; ++i)
        {
            buf.push_back(i + 1);
            helper(i + 1, n, k, buf, ans);
            buf.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> buf;
        vector<vector<int>> ans;
        helper(0, n, k, buf, ans);
        return ans;
    }
};