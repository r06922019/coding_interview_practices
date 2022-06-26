class Solution
{
public:
    int maxScore(vector<int> &p, int k)
    {
        int cur = accumulate(p.begin(), p.begin() + k, 0);
        int ans = cur;
        for (int l = k - 1, r = p.size() - 1; l >= 0; --l, --r)
        {
            cur += p[r] - p[l];
            ans = max(ans, cur);
        }
        return ans;
    }
};