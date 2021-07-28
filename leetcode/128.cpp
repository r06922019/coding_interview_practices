class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> num_set; // sequence ending in k has length of v
        for(auto &num : nums) {
            num_set.insert(num);
        }
        for(auto &num : nums) {
            if(num_set.find(num) != num_set.end()) {
                num_set.erase(num);
                int len = 1, x = num+1;
                while(num_set.find(x) != num_set.end()) {
                    num_set.erase(x);
                    ++x;
                    ++len;
                }
                x = num-1;
                while(num_set.find(x) != num_set.end()) {
                    num_set.erase(x);
                    --x;
                    ++len;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};