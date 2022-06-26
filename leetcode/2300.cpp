class Solution
{
public:
#define ll long long
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int max_spell = *max_element(spells.begin(), spells.end());
        vector<int> divided;
        for (auto potion : potions)
        {
            ll tmp = ceil((double)success / potion);
            if (tmp <= max_spell)
                divided.push_back(tmp);
        }
        vector<int> lookup_table(1e5 + 1, 0);
        for (auto d : divided)
            ++lookup_table[d];
        for (int i = 1; i <= 1e5; ++i)
        {
            lookup_table[i] += lookup_table[i - 1];
        }
        vector<int> ans;
        for (auto spell : spells)
        {
            ans.push_back(lookup_table[spell]);
        }

        return ans;
    }
};