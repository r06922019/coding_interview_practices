class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n = nums.size();
        vector<pair<int, int>> value_index_pairs;
        for (int i = 0; i < n; ++i)
            value_index_pairs.push_back({nums[i], i});
        sort(value_index_pairs.begin(), value_index_pairs.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n;) {
            int cur_min = value_index_pairs[i].first;
            int cur_max = value_index_pairs[i].first;
            vector<int> values, indexs;
            while (i < n) {
                const int& value = value_index_pairs[i].first;
                const int& index = value_index_pairs[i].second;
                if (value - limit > cur_max || value + limit < cur_min) {
                    break;
                }
                cur_max = max(cur_max, value);
                cur_min = min(cur_min, value);
                values.push_back(value);
                indexs.push_back(index);
                ++i;
            }
            sort(indexs.begin(), indexs.end());
            for (int j = 0; j < indexs.size(); ++j) {
                ans[indexs[j]] = values[j];
            }
        }
        return ans;
    }
};
