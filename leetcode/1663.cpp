class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string ans = "";
        while ((k - 1) <= (n - ans.size() - 1) * 26 && (n - ans.size()) > 1)
        {
            ans += 'a';
            k -= 1;
        }
        int k_mod = (k % 26);
        if (k_mod)
        {
            ans += k_mod - 1 + 'a';
            k -= k_mod;
        }
        while (k > 0)
        {
            ans += 'z';
            k -= 26;
        }
        return ans;
    }
};