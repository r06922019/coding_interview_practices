class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> buckets;
        int max_key = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j) {
                int key = i+j;
                // if(buckets.find(key) == buckets.end())
                //     buckets[key] = vector<int>();
                buckets[key].push_back(nums[i][j]);
                max_key = max(max_key, key);
            }
        }
        vector<int> ans;
        for(int key = 0; key <= max_key; ++key) {
            auto &bucket = buckets[key];
            for(auto it = bucket.rbegin(); it != bucket.rend(); ++it) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};