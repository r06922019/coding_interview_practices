class Solution
{
public:
    unordered_map<char, string> digit_to_chars = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return {};
        vector<string> ans = {""};
        for (auto digit : digits)
        {
            vector<string> new_ans;
            for (auto c : digit_to_chars[digit])
            {
                for (auto a : ans)
                {
                    new_ans.push_back(a + c);
                }
            }
            ans = new_ans;
        }
        return ans;
    }
};