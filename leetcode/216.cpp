class Solution
{
public:
    void solve(vector<int> &buf, vector<vector<int> > &ans, int k, int n)
    {
        if (k == 0)
        {
            if (n == 0)
            {
                ans.push_back(buf);
            }
            return;
        }

        int start = 1;
        if (buf.size())
            start = max(start, buf.back() + 1);
        int end = min(9, n);
        for (int i = start; i <= end; ++i)
        {
            buf.push_back(i);
            solve(buf, ans, k - 1, n - i);
            buf.pop_back();
        }
    }

    vector<vector<int> > combinationSum3(int k, int n)
    {
        vector<vector<int> > ans;
        vector<int> buf;
        solve(buf, ans, k, n);
        return ans;
    }
};