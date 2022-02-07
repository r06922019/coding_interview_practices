class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // vector<bool> counter(26, false);
        // for (auto c : s)
        //     counter[c - 'a'] = !counter[c - 'a'];
        // for (auto c : t)
        //     counter[c - 'a'] = !counter[c - 'a'];
        // return 'a' + (max_element(counter.begin(), counter.end()) - counter.begin());
        return (char)(accumulate(t.begin(), t.end(), -accumulate(s.begin(), s.end(), 0)));
    }
};