class Solution
{
public:
    int check(bitset<32> config, vector<vector<int> > &statements)
    {
        int ans = 0, n = statements.size();
        for (int i = 0; i < n; ++i)
        {
            if (config[i])
            {
                // person i should be good
                // check his statements
                for (int j = 0; j < n; ++j)
                    if (statements[i][j] != 2 && statements[i][j] != config[j])
                        return 0;
            }
        }

        // all good, update ans
        for (int i = 0; i < n; ++i)
            if (config[i])
                ++ans;
        return ans;
    }

    int maximumGood(vector<vector<int> > &statements)
    {
        int ans = 0, n = statements.size();
        for (int config = 0; config < (1 << n); ++config)
            ans = max(ans, check(bitset<32>(config), statements));
        return ans;
    }
};