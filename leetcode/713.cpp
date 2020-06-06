class Solution {
public:

    // a * b * c = e ^ (log(a) + log(b) + log(c))
    // product less than k => sum of logs less than log k => sliding window 2-sum
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        double log_k = log(k);
        printf("k = %d, k = %lf\n", k, exp(log_k));
        vector<double> num_logs;
        for(int &num : nums) {
            num_logs.push_back(log(num));
        }

        int l = 0, r = 0, count = 0;
        double cur_sum = 0;
        while(r < n) {
            cur_sum += num_logs[r];
            // printf("adding r %d, cur_sum = %lf\n", r, exp(cur_sum));
            ++r;
            while(l < r && cur_sum >= (log_k-1e-5)) { // important to include 1e-5
                cur_sum -= num_logs[l];
                // printf("removing l = %d, %lf, %lf %d\n", l, num_logs[l], exp(num_logs[l]), nums[l]);
                // printf("cur_sum = %lf\n", exp(cur_sum));
                ++l;
            }
            count += r-l;
            // printf("count = %d\n\n", count);
        }
        return count;
    }


    /*
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0, l = 0, r = 0, n = nums.size();
        long long int cur_product = 1;
        while(r < nums.size()) {
            cur_product *= nums[r];
            ++r;
            while(l < r && cur_product >= k) {
                cur_product /= nums[l];
                ++l;
            }
            cnt += r-l;
        }
        return cnt;
    }
    */
};

