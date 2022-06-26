class Solution
{
public:
    bool digitCount(string num)
    {
        unordered_map<char, int> counter;
        for (auto c : num)
            ++counter[c];
        for (int i = 0; i < num.size(); ++i)
        {
            if (counter[i + '0'] != (num[i] - '0'))
                return false;
        }
        return true;
    }
};