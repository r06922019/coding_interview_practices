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
