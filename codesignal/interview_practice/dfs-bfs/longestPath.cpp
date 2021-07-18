vector<string> get_tokens(string &s) {
    char DELIM = '\f';
    s += DELIM;
    string cur = "";
    vector<string> ret;
    for(auto &c : s) {
        if(c == DELIM) {
            ret.push_back(cur);
            cur = "";
        }
        else {
            cur += c;
        }
    }
    return ret;
}

int sum_of_len(vector<string> &vec) {
    int ans = 0;
    for(auto &s : vec) {
        ans += s.size();
    }
    return ans;
}

bool is_file(string &s) {
    for(auto &c : s) {
        if(c == '.') return true;
    }
    return false;
}

int longestPath(string fileSystem) {
    vector<string> tokens = get_tokens(fileSystem);
    vector<string> cur_path;
    int ans = 0;
    for(auto &token : tokens) {
        int level = 0;
        while(token[level] == '\t') ++level;
        while(cur_path.size() > level) cur_path.pop_back();
        cur_path.push_back(token.substr(level));
        if(is_file(token)) {
            ans = max(ans, (int)(sum_of_len(cur_path) + cur_path.size()-1));
        }
    }
    return ans;
}
