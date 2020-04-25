/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input:
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input:
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
make cdf
binary search for rand
*/

class Solution {
    vector<int> vec;
    int w_sum;
public:
    Solution(vector<int>& w) {
        vec = w;
        for(int i = 1; i < vec.size(); ++i) {
            vec[i] += vec[i-1];
        }
    }

    int pickIndex() {
        double rand_01 = vec.back() * (double)rand()/RAND_MAX;
        if(rand_01 < vec[0]) return 0;

        int l = 0, r = vec.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(vec[mid] < rand_01) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
