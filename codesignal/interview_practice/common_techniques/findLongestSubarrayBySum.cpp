std::vector<int> findLongestSubarrayBySum(int target_sum, std::vector<int> arr) {
    int left = 0, right = 0, cur_sum = 0;
    unordered_map<string, int> ans;
    while(left < arr.size()) {
        while(right < arr.size() && cur_sum+arr[right] <= target_sum) {
            cur_sum += arr[right];
            ++right;
        }
        if(right > left && cur_sum == target_sum) {
            if(ans.size() == 0) { // record left, right
                ans["left"] = left;
                ans["right"] = right;
            }
            else {
                int cur_len = right - left;
                int prev_len = ans["right"] - ans["left"];
                if(cur_len > prev_len) {
                    ans["left"] = left;
                    ans["right"] = right;
                }
            }
        }
        // pop left if added
        if(right > left) {
            cur_sum -= arr[left];
            ++left;
        }
        else {
            ++left;
            ++right;
        }
    }
    vector<int> ret;
    if(ans.size() == 0) {
        ret.push_back(-1);
    }
    else { // +1 for index conversion, real right = right -1
        ret.push_back(ans["left"]+1);
        ret.push_back(ans["right"]-1+1);
    }
    return ret;
}
