class Solution {
public:
    int safe_mod(int x, int m) {
        if(x < 0) {
            x += (((-x)/m) + 1) * m;
        }
        return x % m;
    }

    // O(N)
    /*
    int subarraysDivByK(vector<int>& nums, int K) {
        vector<int> sums = {0};
        for(int &num : nums) {
            sums.push_back(safe_mod(sums.back() + num, K));
        }

        int count = 0;
        vector<int> prev(K, 0);
        for(int &prefix_sum : sums) {
            count += prev[prefix_sum]; // a s.t. (prefix_sum - a) % K == 0
            ++prev[prefix_sum];
        }
        return count;
    }
    */


    int subarraysDivByK(vector<int>& nums, int K) {
        vector<int> mods(K, 0);
        int cur_sum = 0;
        mods[0] = 1;
        for(int &num : nums) {
            cur_sum += num;
            ++mods[ safe_mod(cur_sum, K) ];
        }

        int count = 0;
        for(int &m : mods) {
            count += m * (m-1) / 2;
        }
        return count;
    }
};