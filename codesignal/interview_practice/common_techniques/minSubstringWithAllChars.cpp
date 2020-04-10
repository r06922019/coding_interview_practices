std::string minSubstringWithAllChars(std::string s, std::string t) {
    if(t.size() == 0) return "";

    unordered_set<char> t_set(t.begin(), t.end());
    unordered_map<char, int> cur_map;
    int start_index = 0, end_index = 0;
    unordered_map<string, int> ans;

    while(start_index < s.size()) {
        // set start_index to next possible starting point
        while(start_index < s.size() && t_set.find(s[start_index]) == t_set.end()) {
            ++start_index;
        }
        if(start_index >= end_index)
            end_index = start_index;

        // find end_index for start_index
        while(end_index < s.size() && cur_map.size() < t_set.size()) {
            if(t_set.find(s[end_index]) != t_set.end()) {
                ++cur_map[s[end_index]]; // will auto create new entry if got unseen char
            }
            ++end_index;
        }

        // found match
        if(cur_map.size() == t_set.size()) {
            if(ans.size() == 0) { // not init
                ans["start_index"] = start_index;
                ans["end_index"] = end_index;
            }
            else { // compare length
                int cur_len = end_index - start_index;
                int prev_len = ans["end_index"] - ans["start_index"];
                if(cur_len < prev_len) {
                    ans["start_index"] = start_index;
                    ans["end_index"] = end_index;
                }
            }
        }

        // pop start_index char
        --cur_map[s[start_index]];
        if(cur_map[s[start_index]] == 0) {
            cur_map.erase(s[start_index]);
        }
        ++start_index;
    }

    return s.substr(ans["start_index"], ans["end_index"] - ans["start_index"]);
}
