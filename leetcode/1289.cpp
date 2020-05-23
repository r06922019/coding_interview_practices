class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {

        for(int i = 1; i < arr.size(); ++i) {
            int min_val = INT_MAX;
            vector<int> left_min(arr[0].size(), INT_MAX);
            for(int j = 0; j < arr[i].size(); ++j) {
                left_min[j] = min(min_val, left_min[j]);
                min_val = min(min_val, arr[i-1][j]);
            }

            vector<int> right_min(arr[0].size(), INT_MAX);
            min_val = INT_MAX;
            for(int j = arr[i].size()-1; j >= 0; --j) {
                right_min[j] = min(min_val, right_min[j]);
                min_val = min(min_val, arr[i-1][j]);
            }

            for(int j = 0; j < arr[i].size(); ++j) {
                arr[i][j] += min(left_min[j], right_min[j]);
            }
        }

        auto &v = arr.back();
        return *min_element(v.begin(), v.end());
    }
};