std::string combinationSum(std::vector<int> arr, int target_sum) {
    vector<int> buf;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    vector<int> unique_arr;
    for(int &num : arr) {
        if(unique_arr.empty() || num != unique_arr.back()) {
            unique_arr.push_back(num);
        }
    }

    helper(0, unique_arr, target_sum, buf, ans);
    if(ans.size() == 0) return "Empty";
    string ret = "";
    for(auto &v : ans) {
        ret += "(" + to_string(v[0]);
        for(int i = 1; i < v.size(); ++i)
            ret += " " + to_string(v[i]);
        ret += ")";
    }
    return ret;
}

void helper(int i_start, vector<int> &arr, int target_sum, vector<int> &buf, vector<vector<int>> &ans) {
    if(target_sum == 0) {
        ans.push_back(buf);
        return ;
    }

    for(int i = i_start; i < arr.size() && arr[i] <= target_sum; ++i) {
        buf.push_back(arr[i]);
        helper(i, arr, target_sum - arr[i], buf, ans);
        buf.pop_back();
    }
    return ;
}

