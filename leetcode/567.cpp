class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        vector<int> counter1(26,0), counter2(26,0);
        for(int i = 0; i < s1.size(); ++i) {
            ++counter1[s1[i]-'a'];
            ++counter2[s2[i]-'a'];
        }
        
        if(counter1 == counter2) return true;
        for(int i = s1.size(); i < s2.size(); ++i) {
            --counter2[s2[i-s1.size()]-'a'];
            ++counter2[s2[i]-'a'];
            if(counter1 == counter2) return true;
        }
        return false;
    }
};