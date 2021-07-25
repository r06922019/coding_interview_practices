class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n+1, 0), dp2(n+1, 0);
        dp1[1] = nums[0]; // rob house1
        dp2[1] = 0; // not robbing house1
        for(int i = 2; i <= n; ++i) {
            if(i == n) {
                dp1[i] = dp1[i-1];
            }
            else {
                dp1[i] = max(dp1[i-2]+nums[i-1], dp1[i-1]);
            }
            dp2[i] = max(dp2[i-2]+nums[i-1], dp2[i-1]);
        }
        return max(dp1[n], dp2[n]);
    }
};