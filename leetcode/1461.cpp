class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> seen;
        int mask = (1<<k)-1, cur = 0;
        // for(int i = 0, n = s.size(); i <= n-k; ++i) {
        //     seen.insert(s.substr(i, k)); // can accelerate with rolling hash
        // }
        for(int i = 0, n = s.size(); i < n; ++i) {
            cur = ((cur << 1) | (s[i]-'0')) & mask;
            if(i >= k-1) {
                seen.insert(cur);
            }
        }
        return seen.size() == (1<<k);
    }
};