class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for(auto num : nums) {
            if(LIS.size() == 0 || LIS.back() < num) {
                LIS.push_back(num);
            }
            else {
                int l = 0, r = LIS.size()-1;
                while(l < r) {
                    int mid = l + (r-l)/2;
                    if(LIS[mid] < num) {
                        l = mid+1;
                    }
                    else {
                        r = mid;
                    }
                }
                LIS[l] = num;
            }
        }
        return LIS.size();
    }
};
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
            ans = max(ans, lis[i]);
        }
        return ans;
    }
};
*/