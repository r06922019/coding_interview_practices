class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};

typedef unordered_map<pair<int, int>, int, PairHash> PAIR_HASHMAP;

class Solution {
public:
    PAIR_HASHMAP dp;
    int helper(vector<int>& nums, int index, int target) {
        if(index == nums.size()) {
            return (target == 0)? 1:0;
        }

        if(dp.find({index, target}) != dp.end())
            return dp[{index, target}];

        dp[{index, target}] = helper(nums, index+1, target-nums[index]) + \
            helper(nums, index+1, target+nums[index]);
        return dp[{index, target}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0, target);
    }
};