class Solution
{
public:
    long long smallestNumber(long long num)
    {
        string s = to_string(num);
        if (s[0] == '-')
        {
            sort(s.rbegin(), s.rend() - 1);
            return stoll(s);
        }
        else
        {
            sort(s.begin(), s.end());
            int index = 0;
            while (s[index] == '0' && index < s.size())
                ++index;
            if (index < s.size())
                swap(s[0], s[index]);
        }
        return stoll(s);
    }
};