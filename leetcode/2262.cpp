class Solution
{
public:
    long long appealSum(string s)
    {
        long long ans = 0;
        unordered_map<char, int> seen;
        for (int i = 0, n = s.size(); i < n; ++i)
        {
            auto c = s[i];
            long long x = n - i;
            if (seen.find(c) != seen.end())
            {
                x *= i - seen[c];
            }
            else
            {
                x *= i + 1;
            }
            ans += x;
            seen[c] = i;
        }
        return ans;
    }
};