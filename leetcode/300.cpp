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

class Item {
public:
    int cur_index, prev_index, length;

    Item() {
        cur_index = prev_index = length = 0;
    }

    Item(int _c, int _p, int _l) {
        cur_index = _c;
        prev_index = _p;
        length = _l;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), max_len = 1;
        vector<vector<Item>> LIS_tails;

        for(int i = 0; i < n; ++i) {
            int &num = nums[i];
            LIS_tails.push_back({Item(i, -1, 1)}); // push self
            auto &cur_vec = LIS_tails.back();
            for(int j = 0; j < i; ++j) {
                if(num > nums[j]) {
                    for(auto &prev : LIS_tails[j]) {
                        Item new_item(i, j, prev.length+1);
                        max_len = max(max_len, new_item.length);
                        cur_vec.push_back(new_item);
                    }
                }
            }
        }

        // print tails
        bool print_all_LIS = false;
        if(print_all_LIS) {
            queue<pair<Item, vector<int>>> q;
            for(int i = 0; i < n; ++i) {
                auto &vec = LIS_tails[i];
                printf("%d len = %d\n", i, vec.size());
                for(auto &item : vec) {
                    printf("LIS len = %d\n", item.length);
                    if(item.length == max_len) {
                        q.push({item, {}});
                    }
                }
            }

            while(q.size()) {
                pair<Item, vector<int>> p = q.front();
                q.pop();
                auto &item = p.first;
                auto &vec = p.second;
                vec.push_back(nums[item.cur_index]);
                if(item.prev_index == -1) {
                    reverse(vec.begin(), vec.end());
                    for(auto &num : vec) {
                        printf("%d ", num);
                    }
                    printf("\n");
                }
                else {
                    for(auto &prev_item : LIS_tails[item.prev_index]) {
                        if(prev_item.length == item.length-1) {
                            q.push({prev_item, vec});
                        }
                    }
                }
            }
        }

        return max_len;
    }
};

*/


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