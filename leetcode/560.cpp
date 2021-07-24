class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> acc_sums = {0};
        for(auto &num : nums) {
            acc_sums.push_back(acc_sums.back() + num);
        }
        int cnt = 0;
        unordered_map<int, int> count_of_sums;
        for(auto &acc_sum : acc_sums) {
            int target = acc_sum - k;
            if(count_of_sums.find(target) != count_of_sums.end()) {
                cnt += count_of_sums[target];
            }
            ++count_of_sums[acc_sum];
        }
        return cnt;
    }
};