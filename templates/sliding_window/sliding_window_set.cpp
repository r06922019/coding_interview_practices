class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0) return false;
        set<long long int> s;
        for(int i = 0, n = nums.size(); i < n; ++i) {
            auto &num = nums[i];
            if(i >= (k+1)) {
                auto &to_remove = nums[i-(k+1)];
                s.erase(to_remove);
            }
            if(s.find(num) != s.end()) {
                return true;
            }
            auto p = s.insert(num);
            auto it = p.first;
            if(s.size() > 1) {
                if(it != s.begin()) {
                    auto prev = it; --prev;
                    if(num - *prev <= t) return true;
                }
                auto next = it; ++next;
                if(next != s.end()) {
                    if(*next - num <= t) return true;
                }
            }
        }
        return false;
    }
};