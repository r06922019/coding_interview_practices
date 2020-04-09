std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int target_sum) {
    vector<vector<int>> ans;
    vector<int> buf;
    helper(arr, target_sum, 0, buf, ans);
    return ans;
}

void helper(vector<int> &arr, int target_sum, int i_start, vector<int> &buf, vector<vector<int>> &ans) {
    if(target_sum == 0) {
        ans.push_back(buf);
        return ;
    }

    for(int i = i_start; i < arr.size() && arr[i] <= target_sum; ++i) {
        if(i == i_start || arr[i] != arr[i-1]) {
            buf.push_back(arr[i]);
            helper(arr, target_sum-arr[i], i+1, buf, ans);
            buf.pop_back();
        }
    }
    return ;
}

