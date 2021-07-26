class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> acc_odd_nums = {0};
        for(auto &num : nums) {
            if(num % 2 == 0) {
                acc_odd_nums.push_back(acc_odd_nums.back());
            }
            else {
                acc_odd_nums.push_back(acc_odd_nums.back()+1);
            }
        }
        int ans = 0;
        unordered_map<int, int> counter;
        for(auto &count : acc_odd_nums) {
            if(count >= k && counter.find(count-k) != counter.end()) {
                ans += counter[count-k];
            }
            ++counter[count];
        }
        return ans;
    }
};