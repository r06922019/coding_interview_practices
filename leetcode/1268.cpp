class Solution
{
public:
    vector<vector<string> > suggestedProducts(vector<string> &products, string sW)
    {
        vector<vector<string> > ans;
        vector<string> cands = products;
        for (int i = 0; i < sW.size(); ++i)
        {
            vector<string> v;
            for (auto s : cands)
                if (s[i] == sW[i])
                    v.push_back(s);
            cands = v;
            ans.push_back(v);
        }

        const int LEN = 3;
        for (int i = 0; i < ans.size(); ++i)
        {
            auto &v = ans[i];
            sort(v.begin(), v.end());
            if (v.size() > LEN)
                ans[i] = vector<string>(v.begin(), v.begin() + LEN);
        }
        return ans;
    }
};