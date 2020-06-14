class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; ++i) {
            // extract i-th bit from n
            // put to 31-i position in ans
            int n_bit = n & (1<<i);
            if(n_bit) // n_bit != 0
                ans = ans | (1 << (31-i));
        }
        return ans;
    }
};

