class Solution {
public:
    int count_palin(string &s, int l, int r) {
        if(l < 0 || r >= s.size() || s[l] != s[r]) return 0;
        int ret = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            ++ret;
            --l;
            ++r;
        }
        return ret;
    }
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; ++i) {
            ans += count_palin(s, i, i);
            ans += count_palin(s, i, i+1);
        }
        return ans;
    }
};