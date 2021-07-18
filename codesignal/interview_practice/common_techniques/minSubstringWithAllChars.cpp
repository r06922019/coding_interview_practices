string minSubstringWithAllChars(string s, string t) {
    if(t.empty()) return "";
    unordered_set<char> t_set(t.begin(), t.end());
    unordered_map<char, int> cur_char_counts;
    int l = 0;
    vector<int> ans;
    for(int r = 0; r < s.size(); ++r) {
        if(t_set.find(s[r]) != t_set.end()) {
            ++cur_char_counts[s[r]];
        }
        if(cur_char_counts.size() == t_set.size()) {
            // discard unused l
            while(t_set.find(s[l]) == t_set.end() || cur_char_counts[s[l]] > 1) {
                if(cur_char_counts.find(s[l]) != cur_char_counts.end())
                    --cur_char_counts[s[l]];
                ++l;
            }
            // see if we take it as an ans
            if(ans.empty()) {
                ans = {l, r};
            }
            else if((r-l) < (ans[1]-ans[0])) {
                ans = {l, r};
            }
            // discard until this is no longer an ans for next ans
            while(cur_char_counts.size() == t_set.size()) {
                if(t_set.find(s[l]) != t_set.end()) {
                    --cur_char_counts[s[l]];
                    if(cur_char_counts[s[l]] == 0)
                        cur_char_counts.erase(s[l]);
                }
                ++l;
            }
        }
    }
    return s.substr(ans[0], ans[1]-ans[0]+1);
}
