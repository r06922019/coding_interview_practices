class PairHash {
public:
    size_t operator()(const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, PairHash> cache;
    int minSpaceWastedKResizing(vector<int>& nums, int n, int k) {
        if(n == 0) return 0;
        if(k == 0) {
            int max_num = *max_element(nums.begin(), nums.begin()+n);
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                ans += max_num - nums[i];
            }
            return ans;
        }
        pair<int, int> key = {n, k};
        if(cache.find(key) != cache.end()) return cache[key];
        // pick a size that covers i elements
        int ans = INT_MAX;
        int cur_sum = 0, cur_max = 0;
        for(int i = 1; i <= n; ++i) {
            auto num = nums[n-i];
            cur_sum += num;
            cur_max = max(num, cur_max);
            ans = min(ans, cur_max*i-cur_sum + minSpaceWastedKResizing(nums, n-i, k-1));
        }
        cache[key] = ans;
        return ans;
    }

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        return minSpaceWastedKResizing(nums, nums.size(), k);
    }
};