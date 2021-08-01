class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long x = 1;
        while( ((x+1)*(x+2*x*x))*2 < neededApples) {
            ++x;
        }
        return 8*x;
    }
};