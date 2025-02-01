class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int, int> counter;
        for (auto c : s) {
            ++counter[c];
        }
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] != s[i]) {
                if (counter[s[i - 1]] == (s[i - 1] - '0') &&
                    counter[s[i]] == (s[i] - '0'))
                    return s.substr(i - 1, 2);
            }
        }
        return "";
    }
};
