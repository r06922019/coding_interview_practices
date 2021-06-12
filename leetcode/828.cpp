class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0, n = s.size();
        long long int tmp = 0;
        const int MOD = 1e9+7;
        vector<int> prev(n, -1), next(n, n), seen(26, -1);
        for(int i = 0; i < n; ++i) {
            int index = s[i] - 'A';
            if(seen[index] != -1) {
                prev[i] = seen[index];
            }
            seen[index] = i;
        }
        for(int i = 0; i < 26; ++i)
            seen[i] = -1;
        for(int i = n-1; i >= 0; --i) {
            int index = s[i] - 'A';
            if(seen[index] != -1) {
                next[i] = seen[index];
            }
            seen[index] = i;
        }
        for(int i = 0; i < n; ++i) {
            tmp = (i - prev[i]);
            tmp = tmp * (next[i] - i);
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }
};