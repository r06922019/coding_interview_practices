class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), dupped_size = 0;
        for(auto &num : arr) {
            if(num == 0) {
                ++dupped_size;
            }
            ++dupped_size;
        }
        for(int i = n-1; i >= 0; --i, --dupped_size) {
            if(dupped_size <= n) {
                arr[dupped_size-1] = arr[i];
            }
            if(arr[i] == 0) {
                --dupped_size;
                if(dupped_size <= n) {
                    arr[dupped_size-1] = arr[i];
                }
            }
        }
        return ;
    }
};