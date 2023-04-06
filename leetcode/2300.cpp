class Solution
{
public:
    int check(vector<int> &pp, long long x)
    {
        int l = 0, r = pp.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (pp[mid] < x)
                l = mid + 1;
            else
                r = mid;
        }
        return pp.size() - l;
    }

    vector<int> successfulPairs(vector<int> &spells, vector<int> &pp, long long success)
    {
        sort(pp.begin(), pp.end());
        vector<int> ans;
        for (auto s : spells)
            ans.push_back(check(pp, (success % s) ? (success / s) + 1 : success / s));
        return ans;
    }
};