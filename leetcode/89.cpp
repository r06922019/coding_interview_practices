class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> arr = {0};
        for(int i = 0; i < n; ++i) {
            int cur_n = arr.size();
            for(int j = cur_n-1; j >= 0; --j) {
                arr.push_back(arr[j]+(1<<i));
            }
        }
        return arr;
    }
};