class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int max_3_power = pow(3, (int)(log10(INT_MAX) / log10(3)));
        return max_3_power % n == 0;
    }
};