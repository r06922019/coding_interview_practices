class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (int i = 0, n = s.size(); i < n / 2; ++i)
            swap(s[i], s[n - i - 1]);
    }
};