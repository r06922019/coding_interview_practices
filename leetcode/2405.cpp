class Solution
{
public:
    int partitionString(string s)
    {
        int cnt = 1;
        unordered_set<char> seen;
        for (auto c : s)
        {
            if (seen.find(c) != seen.end())
            {
                ++cnt;
                seen.clear();
            }
            seen.insert(c);
        }
        return cnt;
    }
};