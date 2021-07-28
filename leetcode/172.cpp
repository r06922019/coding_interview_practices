class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        int x = 5;
        while(x <= n) {
            fives += n/x;
            x *= 5;
        }
        int twos = 0;
        x = 2;
        while(x <= n) {
            twos += n/x;
            x *= 2;
        }
        return min(twos, fives);
    }
};