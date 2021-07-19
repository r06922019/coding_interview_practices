class Solution {
public:
    int hamming(int x) {
        int cnt = 0;
        while(x) {
            ++cnt;
            x = x & (x-1);
        }
        return cnt;
    }

    vector<int> countBits(int n) {
        // vector<int> ans;
        // for(int i = 0; i <= n; ++i) {
        //     ans.push_back(hamming(i));
        // }
        vector<int> ans(n+1, 0);
        for(int i = 1; i < n+1; ++i) {
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};