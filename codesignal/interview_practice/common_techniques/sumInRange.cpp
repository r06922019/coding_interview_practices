int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    vector<int> acc_sum(nums.size(), 0);
    int MOD = 1000000000+7;

    acc_sum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        acc_sum[i] = acc_sum[i-1] + nums[i];
    }

    int ans = 0;
    for(auto &q:queries) {
        int q0 = (q[0] == 0)? 0:acc_sum[ q[0]-1 ];
        int q1 = acc_sum[ q[1] ];
        int tmp = q1 - q0;
        ans += tmp % MOD;
        if(ans >= MOD) {
            ans = ans % MOD;
        }
        else if(ans < 0) {
            ans += MOD;
        }
    }

    return ans;
}
