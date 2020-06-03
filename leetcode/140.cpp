class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> cache;
        return helper(s, 0, word_set, cache);
    }

    bool helper(string &s, int start, unordered_set<string> &word_set, unordered_map<int, bool> &cache) {
        if(start > s.size()) return false;
        if(start == s.size()) return true;

        if(cache.find(start) != cache.end()) return cache[start];
        bool ret = false;
        for(auto &word : word_set) {
            if(start + word.size() <= s.size()) {
                if(word == s.substr(start, word.size())) {
                    ret = ret || helper(s, start + word.size(), word_set, cache);
                }
            }
        }
        cache[start] = ret;
        return cache[start];
    }
};