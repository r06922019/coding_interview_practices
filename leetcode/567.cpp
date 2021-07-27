class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_counter(26, 0), s2_counter(26, 0);
        for(auto &c : s1) {
            ++s1_counter[c-'a'];
        }
        for(int i = 0; i < s2.size(); ++i) {
            if(i >= s1.size())
                --s2_counter[s2[i-s1.size()]-'a'];
            ++s2_counter[s2[i]-'a'];
            if(s1_counter == s2_counter)
                return true;
        }
        return false;
    }
};