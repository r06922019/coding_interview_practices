class Item {
public:
    int index, value;
    Item(int _i, int _v) {
        index = _i;
        value = _v;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<Item> deq;
        for(int i = 0; i < nums.size(); ++i) {
            while(deq.size() && deq.front().index + k <= i) { // pop 0 when got 3
                deq.pop_front();
            }
            while(deq.size() && deq.back().value < nums[i]) {
                deq.pop_back();
            }
            deq.emplace_back(i, nums[i]);
            if(i >= k-1)
                ans.push_back(deq.front().value);
        }
        return ans;
    }
};