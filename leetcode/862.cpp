class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> acc = {0};
        for(auto &num : nums) {
            acc.push_back(acc.back() + num);
        }

        int min_len = INT_MAX;

        // O(N^2)
        // for(int i = 0; i < n; ++i) {
        //     for(int j = i+1; j <= n; ++j) {
        //         if(acc[j] - acc[i] >= k) {
        //             if(j-i < min_len) {
        //                 min_len = j-i;
        //             }
        //         }
        //     }
        // }

        deque<pair<int, int>> deq;
        for(int i = 0; i <= n; ++i) {
            auto num = acc[i];
            // popping all arrays that meet the conditions
            while(deq.size() && (num - deq.front().second) >= k) {
                min_len = min(min_len, i-deq.front().first);
                deq.pop_front();
            }
            // num is better because if
            // deq.back() forms a result with some later elemnt
            // changing to num will always result in a shorter ans
            while(deq.size() && deq.back().second >= num) {
                deq.pop_back();
            }
            deq.push_back({i, num});
        }

        if(min_len == INT_MAX) return -1;
        return min_len;
    }
};