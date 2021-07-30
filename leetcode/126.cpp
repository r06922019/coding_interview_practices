class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> word_set(wordList.begin(), wordList.end()), visited;
        if(word_set.find(endWord) == word_set.end()) return ans;
        queue<pair<string, vector<string>>> q;

        q.push({beginWord, {beginWord}});
        visited.insert(beginWord);
        bool found = false;
        while(!found && q.size()) {
            int q_size = q.size();
            unordered_set<string> cur_visited;
            while(q_size--) {
                auto p = q.front();
                q.pop();
                auto s = p.first;
                auto vec = p.second;
                if(s == endWord) {
                    found = true;
                    ans.push_back(vec);
                    continue;
                }
                for(int i = 0; i < s.size(); ++i) {
                    char c = s[i];
                    for(char j = 'a'; j <= 'z'; ++j) {
                        s[i] = j;
                        if(word_set.find(s) != word_set.end() && visited.find(s) == visited.end()) {
                            vec.push_back(s);
                            q.push({s, vec});
                            vec.pop_back();
                            cur_visited.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
            for(auto &s : cur_visited) {
                visited.insert(s);
            }
        }
        return ans;
    }
};