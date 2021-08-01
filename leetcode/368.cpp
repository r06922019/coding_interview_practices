class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> prev(n, -1), count(n, 1);
        int max_size = 0, max_index = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(nums[i] % nums[j] == 0 && 1 + count[j] > count[i]) {
                    count[i] = count[j]+1;
                    prev[i] = j;
                }
            }
            if(count[i] > max_size) {
                max_size = count[i];
                max_index = i;
            }
        }
        vector<int> ans;
        int index = max_index;
        while(prev[index] != -1) {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        ans.push_back(nums[index]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};