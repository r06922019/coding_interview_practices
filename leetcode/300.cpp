class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> LIS_tails, LIS;

        for(int i = 0; i < n; ++i) {
            int &num = nums[i];
            if(LIS_tails.empty() || LIS_tails.back() < num) {
                LIS_tails.push_back(num);
                LIS = LIS_tails;
            }
            else {
                for(int j = 0; j < LIS_tails.size(); ++j) {
                    if(LIS_tails[j] >= num) {
                        LIS_tails[j] = num;
                        break;
                    }
                }
            }
        }

        // print tail
        // for(auto &num : LIS) {
        //     printf("%d ", num);
        // }
        // printf("\n");

        return LIS_tails.size();
    }
};

/*
// nlogn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> tails; //tails[i] -> tail of LIS of len i+1
        for(int &num : nums) {
            // find appropriate pos for num in tails
            if(tails.empty() || tails.back() < num) {
                tails.push_back(num);
            }
            else if(tails.front() < num) {
                int l = 0, r = tails.size()-1;
                while(l < r) {
                    int mid = l + (r-l)/2;
                    if(tails[mid] < num) {
                        l = mid + 1;
                    }
                    else {
                        r = mid;
                    }
                }
                tails[l] = num;
            }
            else {
                tails.front() = num;
            }

            // for(int &t:tails) {
            //     printf("%d ", t);
            // }
            // printf("\n");
        }
        return tails.size();

        // if(nums.empty()) return 0;
        // int max_len = 1;
        // unordered_map<int, int> mem;
        // for(int i = 0; i < nums.size(); ++i) {
        //     int &num = nums[i];
        //     mem[num] = 1;
        //     for(auto &it : mem) {
        //         if(it.first < num) {
        //             mem[num] = max(mem[num], it.second+1);
        //             max_len = max(max_len, mem[num]);
        //         }
        //     }
        // }
        // return max_len;
    }
};
*/