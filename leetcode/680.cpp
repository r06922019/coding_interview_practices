class Solution
{
public:
    bool solve(string s, int l, int r, int d)
    {
        if (d < 0)
            return false;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return solve(s, l, r - 1, d - 1) || solve(s, l + 1, r, d - 1);
            }
            ++l, --r;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        return solve(s, 0, s.size() - 1, 1);
    }
};