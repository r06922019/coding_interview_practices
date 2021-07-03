class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0, n = s.size();
        unordered_set<char> seen;
        while(r < n) {
            while(r < n && seen.find(s[r]) == seen.end()) {
                seen.insert(s[r]);
                ++r;
            }
            ans = max(ans, r-l);
            seen.erase(s[l]);
            ++l;
        }
        return ans;
    }
};