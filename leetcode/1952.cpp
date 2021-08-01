class Solution {
public:
    bool is_prime(int x) {
        if(x <= 1) return false;
        if(x == 2) return true;
        if(x % 2 == 0) return false;
        for(int i = 3; i*i <= x; ++i) {
            if(x % i == 0) return false;
        }
        return true;
    }
    bool isThree(int n) {
        for(int i = 2; i <= 100; ++i) {
            if(is_prime(i) && i*i == n)
                return true;
        }
        return false;
    }
};