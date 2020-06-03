class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& word_list) {
        // sort list by length
        sort(word_list.begin(), word_list.end(), [](const string & a, const string & b) {
            return a.size() < b.size() || (a.size() == b.size() && a < b);
        });

        // unordered_set<string> word_set(word_list.begin(), word_list.end());
        unordered_set<string> word_set;
        vector<string> ret;
        for(auto &query : word_list) {
            unordered_map<int, bool> cache;
            if(query.size()) {
                if(helper(query, 0, word_set, cache)) {
                    ret.push_back(query);
                }
                word_set.insert(query);
            }
        }
        return ret;
    }

    bool helper(string query, int start, unordered_set<string> &word_set, unordered_map<int, bool> &cache) {
        if(cache.find(start) != cache.end()) return cache[start];

        bool ret = false;
        int cur_len = query.size() - start;
        // if(word_set.size() < cur_len) {
        if(false) { // slower
            for(auto &word : word_set) {
                int new_start = start + word.size();
                if(new_start <= query.size()) {
                    if(word == query.substr(start, word.size())) {
                        if(new_start == query.size()) {
                            ret = true;
                            break;
                        }
                        else {
                            ret = ret || helper(query, new_start, word_set, cache);
                        }
                    }
                }
            }
        }
        else {
            if(word_set.find(query.substr(start)) != word_set.end()) {
                ret = true;
            }
            for(int len = cur_len-1; len >= 1 && !ret; --len) {
            // for(int len = 1; len <= cur_len && !ret; ++len) {
                if(word_set.find(query.substr(start, len)) != word_set.end()) {
                    ret = ret || helper(query, start + len, word_set, cache);
                }
            }
        }
        cache[start] = ret;
        return ret;
    }

};