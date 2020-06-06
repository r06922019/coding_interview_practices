class Solution {
public:
    // record indexs
    int findShortestSubArray(vector<int>& nums) {
        int MAX_NUM = 50000;
        vector<int> left(MAX_NUM, INT_MAX), right(MAX_NUM, INT_MIN), counts(MAX_NUM, 0);
        for(int i = 0; i < nums.size(); ++i) {
            int &num = nums[i];
            left[num] = min(left[num], i);
            right[num] = max(right[num], i);
            ++counts[num];
        }

        int min_len = INT_MAX, degree = *max_element(counts.begin(), counts.end());
        for(int i = 0; i < MAX_NUM; ++i) {
            if(counts[i] == degree) {
                min_len = min(min_len, right[i] - left[i] + 1);
            }
        }
        return min_len;
    }
    /*
    // sliding window
    int findShortestSubArray(vector<int>& nums) {
        vector<int> counter(50000, 0);
        for(int &num : nums) {
            ++counter[num];
        }

        int degree = 0;
        for(int &count : counter) {
            degree = max(degree, count);
        }

        vector<int> cur_counter(50000, 0);
        int l = 0, r = 0, min_len = INT_MAX, n = nums.size();
        while(r < n) {
            bool keep_adding = true;
            while(r < n && keep_adding) {
                ++cur_counter[nums[r]];
                if(cur_counter[nums[r]] == degree) {
                    keep_adding = false;
                }
                ++r;
            }
            // pop as many as can
            while(l < r && !keep_adding) {
                if(cur_counter[nums[l]] != degree) {
                    --cur_counter[nums[l]];
                    ++l;
                }
                else {
                    break;
                }
            }

            min_len = min(min_len, r - l);
            if(l < r) {
                --cur_counter[nums[l]];
                ++l;
            }
        }
        return min_len;
    }
    */
};