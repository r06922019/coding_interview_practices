class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> counter;
        for(int &cod : barcodes) {
            ++counter[cod];
        }

        vector<vector<int>> code_groups;
        for(auto &it : counter) {
            int code = it.first, count = it.second;
            code_groups.push_back({count, code});
        }

        sort(code_groups.rbegin(), code_groups.rend());

        // expand
        vector<int> sorted_with_count;
        for(auto &group : code_groups) {
            int code = group[1], count = group[0];
            while(count--) {
                sorted_with_count.push_back(code);
            }
        }

        vector<int> ans(barcodes.size(), 0);
        int index = 0, n = barcodes.size();
        for(int i = 0; i < n; i += 2, ++index) {
            ans[i] = sorted_with_count[index];
        }

        for(int i = 1; i < n; i += 2, ++index) {
            ans[i] = sorted_with_count[index];
        }
        return ans;
    }
};