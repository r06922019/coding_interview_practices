class Solution {
public:
    int kthGrammar(int n, int k) {
        int ans = 0;
        return helper(n, k, ans);
    }

    int helper(int n, int k, int &ans) {
        if(n == 1) return ans;
        if(k > (1 << (n-2))) {
            ans ^= 1;
            k -= (1 << (n-2));
        }
        return helper(n-1, k, ans);
    }
};