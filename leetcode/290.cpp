class Solution {
public:
    
    vector<string> split(string s, char delim) {
        if(s.size() == 0) return {};
        vector<string> result = {""};
        for(auto c : s) {
            if(c == delim) {
                result.push_back("");
            }
            else {
                result.back() += c;
            }
        }
        return result;
    }
    
    bool wordPattern(string pattern, string s_) {
        vector<string> split_s = split(s_, ' ');
        if(split_s.size() != pattern.size()) return false;
        unordered_map<string, string> p2s, s2p;
        int n = split_s.size();
        for(int i = 0; i < n; ++i) {
            string p = pattern.substr(i, 1), s = split_s[i];
            if(p2s.find(p) == p2s.end() && s2p.find(s) != s2p.end()) return false;
            else if(p2s.find(p) != p2s.end() && s2p.find(s) == s2p.end()) return false;
            else if(p2s.find(p) == p2s.end() && s2p.find(s) == s2p.end()) {
                p2s[p] = s;
                s2p[s] = p;
            }
            else {
                if(p2s[p] != s || s2p[s] != p) return false;
            }
        }
        return true;
    }
};