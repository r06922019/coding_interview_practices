class Solution
{
public:
    // TODO
    string removeDuplicateLetters(string s)
    {
        vector<char> v;
        unordered_map<char, bool> seen;
        unordered_map<char, int> last_index;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            last_index[s[i]] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            auto c = s[i];
            if (seen.find(c) != seen.end() && seen[c])
                continue;
            while (v.size() && v.back() > c && last_index[v.back()] > i)
            {
                seen[v.back()] = false;
                v.pop_back();
            }
            seen[c] = true;
            v.push_back(c);
        }

        return string(v.begin(), v.end());
    }
};