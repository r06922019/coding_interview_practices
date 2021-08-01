/*
5833. Count Number of Special Subsequences
A sequence is special if it consists of a positive number of 0s,
followed by a positive number of 1s, then a positive number of 2s.

For example, [0,1,2] and [0,0,1,1,1,2] are special.
In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
Given an array nums (consisting of only integers 0, 1, and 2),
return the number of different subsequences that are special.
Since the answer may be very large, return it modulo 10^9 + 7.

A subsequence of an array is a sequence that can be derived from
the array by deleting some or no elements without changing
the order of the remaining elements. Two subsequences are different
if the set of indices chosen are different.

Example 1:

Input: nums = [0,1,2,2]
Output: 3
Example 2:

Input: nums = [2,2,0,0]
Output: 0
Explanation: There are no special subsequences in [2,2,0,0].
Example 3:

Input: nums = [0,1,2,0,1,2]
Output: 7

*/

class Solution {
public:
    const int MOD = 1e9+7;
    int mod(int x) {
        x %= MOD;
        if(x < 0) x += MOD;
        return x;
    }

    int mod(long long x) {
        x %= MOD;
        if(x < 0) x += MOD;
        return x;
    }

    int add(int a, int b) {
        return mod(mod(a) + mod(b));
    }

    int mul(int a, int b) {
        long long tmp = a;
        tmp *= mod(b);
        return mod(tmp);
    }

    int pow2(int x) {
        int num = 1;
        int base = 2;
        while(x) {
            if(x & 1) {
                num = mul(num, base);
            }
            x >>= 1;
            base = mul(base, base);
        }
        return num;
    }

    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        // len <= n that ends at x
        int zeros = 0, ones = 0, twos = 0;
        for(auto &num : nums) {
            if(num == 0) {
                ++zeros;
            }
            else if(num == 1) {
                // every one can concat to previous ones and all non-empty zeros
                // ones += ones + 2**zeros-1
                ones = add(ones, add(ones, add(pow2(zeros), -1)));
            }
            else {
                // every two can concat to previous twos and all ones
                // twos += ones + twos
                twos = add(twos, add(twos, ones));
            }
        }
        return twos;
    }
};

