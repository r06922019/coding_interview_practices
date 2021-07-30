class Solution {
public:
    void helper(string &s, int index,
               unordered_set<string> &word_set, int max_len,
               vector<string> &buf, vector<string> &ans) {
        if(index >= s.size()) {
            if(index == s.size()) {
                string tmp = "";
                for(auto &token : buf) tmp += token + " ";
                tmp.pop_back();
                ans.push_back(tmp);
            }
            return ;
        }

        for(int len = 1; len <= max_len && index + len <= s.size(); ++len) {
            if(word_set.find(s.substr(index, len)) != word_set.end()) {
                buf.push_back(s.substr(index, len));
                helper(s, index+len, word_set, max_len, buf, ans);
                buf.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<string> ans;
        vector<string> buf;
        int max_len = 0;
        for(auto &word : wordDict) max_len = max(max_len, (int)word.size());
        helper(s, 0, word_set, max_len, buf, ans);
        return ans;
    }
};