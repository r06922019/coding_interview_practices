class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l = 0, repeat = 0, ans = 0;
        unordered_map<int, int> counter;
        for(int r = 0; r < nums.size(); ++r) {
            // the set has changed so need to zero our repeat
            if(counter.find(nums[r]) == counter.end()
               && counter.size() == k) {
                --counter[nums[l]];
                counter.erase(nums[l]);
                ++l;
                repeat = 0;
            }
            ++counter[nums[r]];
            // aggregate the repeated left side
            while(counter[nums[l]] > 1) {
                ++repeat;
                --counter[nums[l]];
                ++l;
            }
            // previous repeat count and current one that doesn't include the repeat
            if(counter.size() == k)
                ans += repeat + 1;
        }

        return ans;
    }
};