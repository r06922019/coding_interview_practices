void helper(int index, vector<int> &arr, int sum, vector<int> &buf, string &ans) {
    if(sum <= 0 || index >= arr.size()) {
        if(sum == 0) {
            string tmp = to_string(buf[0]);
            for(int i = 1; i < buf.size(); ++i) {
                tmp += " " + to_string(buf[i]);
            }
            ans += "(" + tmp + ")";
        }
        return ;
    }

    for(int i = index; i < arr.size() && arr[i] <= sum; ++i) {
        buf.push_back(arr[i]);
        helper(i, arr, sum-arr[i], buf, ans);
        buf.pop_back();
    }
}

string combinationSum(vector<int> arr, int sum) {
    set<int> ans_set(arr.begin(), arr.end());
    arr = vector<int>(ans_set.begin(), ans_set.end());
    vector<int> buf;
    string ans = "";
    helper(0, arr, sum, buf, ans);
    if(ans.empty())
        ans = "Empty";
    return ans;
}
