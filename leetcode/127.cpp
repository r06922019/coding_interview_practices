class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end()), visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                auto cur = q.front();
                q.pop();
                if(cur == endWord) return steps;
                for(int i = 0; i < cur.size(); ++i) {
                    char orig = cur[i];
                    for(int j = 'a'; j <= 'z'; ++j) {
                        cur[i] = j;
                        if(word_set.find(cur) != word_set.end() &&
                          visited.find(cur) == visited.end()) {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = orig;
                }
            }
            ++steps;
        }
        return 0;
    }
};