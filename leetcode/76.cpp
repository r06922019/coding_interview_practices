class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_counter, cur_counter;
        for(char &c : t) {
            ++t_counter[c];
        }

        int l = 0, r = 0, cur_len = 0, min_len = INT_MAX;
        string ans = "";
        while(r < s.size()) {

            // extend
            while(r < s.size() && cur_len < t.size()) {
                char &c = s[r];
                if(t_counter.find(c) != t_counter.end()) {
                    if(cur_counter.find(c) == cur_counter.end() || cur_counter[c] < t_counter[c]) {
                        ++cur_len;
                    }
                    ++cur_counter[c];
                }
                ++r;
            }

            // pop useless ones
            while(l < r && cur_len == t.size()) {
                char &c = s[l];
                if(t_counter.find(c) == t_counter.end()) {
                    ++l;
                }
                else if(cur_counter[c] > t_counter[c]) {
                    --cur_counter[c];
                    ++l;
                }
                else {
                    break;
                }
            }

            // record len if valid
            if(cur_len == t.size() && (r-l) < min_len) {
                min_len = r-l;
                ans = s.substr(l, r-l);
            }

            // pop 1 useful
            while(l < r && cur_len == t.size()) {
                char &c = s[l];
                if(t_counter.find(c) != t_counter.end()) {
                    if(cur_counter[c] == t_counter[c]) {
                        --cur_len;
                    }
                    --cur_counter[c];
                }
                ++l;
            }
        }
        return ans;
    }
};