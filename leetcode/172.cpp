class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        int x = 5;
        while(x <= n) {
            fives += n/x;
            x *= 5;
        }
        return fives;
    }
};