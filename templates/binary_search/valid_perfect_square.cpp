class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(mid >= num / mid) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return (long long int)l * (long long int)l == (long long int)num;
    }
};