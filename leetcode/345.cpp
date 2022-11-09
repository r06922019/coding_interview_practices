class Solution
{
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    bool is_vowel(char c)
    {
        return vowels.find(tolower(c)) != vowels.end();
    }
    string reverseVowels(string s)
    {
        vector<char> v;
        for (auto c : s)
        {
            if (is_vowel(c))
                v.push_back(c);
        }
        for (auto &c : s)
        {
            if (is_vowel(c))
            {
                c = v.back();
                v.pop_back();
            }
        }
        return s;
    }
};