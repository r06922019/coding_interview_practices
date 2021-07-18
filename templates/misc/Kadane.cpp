// dp[i] = max_that_ends_at_i
// dp[i] = max(arr[i], arr[i]+dp[i-1]) -> concat arr[i] to ans previous
// maintain another global max
int arrayMaxConsecutiveSum2(vector<int> inputArray) {
    int cur_sum = inputArray[0];
    int ans = inputArray[0];
    for(int i = 1; i < inputArray.size(); ++i) {
        if(cur_sum < 0) cur_sum = 0;
        cur_sum += inputArray[i];
        ans = max(ans, cur_sum);
    }
    return ans;
}
