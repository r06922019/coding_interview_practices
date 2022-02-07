class Solution
{
public:
    int minimumSum(int num)
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return 10 * (s[0] + s[1] - '0' - '0') + (s[2] + s[3] - '0' - '0');
    }
};