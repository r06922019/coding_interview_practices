class Solution
{
public:
    int romanToInt(string s)
    {
        /*
        I can be placed before V (5) and X (10) to make 4 and 9.
        X can be placed before L (50) and C (100) to make 40 and 90.
        C can be placed before D (500) and M (1000) to make 400 and 900.
        */
        unordered_map<char, unordered_map<char, int>> valid_pairs = {
            {'I', {{'V', 4}, {'X', 9}}},
            {'X', {{'L', 40}, {'C', 90}}},
            {'C', {{'D', 400}, {'M', 900}}}};
        /*
        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000
        */
        unordered_map<char, int> char_to_value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int ans = 0;
        int index = 0;
        while (index < s.size())
        {
            char cur_char = s[index];
            ++index;
            if (index < s.size() &&
                valid_pairs[cur_char].find(s[index]) != valid_pairs[cur_char].end())
            {
                ans += valid_pairs[cur_char][s[index]];
                ++index;
            }
            else
            {
                ans += char_to_value[cur_char];
            }
        }
        return ans;
    }
};