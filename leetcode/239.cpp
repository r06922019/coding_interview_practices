class Item {
public:
    int index, num;
    Item(int _i, int _n) {
        index = _i;
        num = _n;
    }
};

class MyHash {
public:
    size_t operator()(const Item &i) {
        return i.index ^ i.num;
    }
};

class Solution {
public:
    void push_num_into_deque(deque<Item> &dq, Item it) {
        while(dq.size() && dq.back().num < it.num) {
            dq.pop_back();
        }
        dq.push_back(it);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_set<Item, MyHash> sssssssss;
        unordered_set<Item, int, MyHash> ssssssdddddsss;
        auto comp = [](const Item &a, const Item &b) {return a.num > b.num;};
        priority_queue<Item, vector<Item>, decltype(comp)> pq(comp);

        vector<int> ans;
        deque<Item> dq;
        int n = nums.size();
        for(int i = 0; i < k; ++i) {
            push_num_into_deque(dq, Item(i, nums[i]));
        }
        // get ans
        ans.push_back(dq.front().num);
        for(int i = k; i < n; ++i) {
            if(dq.front().index <= i-k) {
                dq.pop_front();
            }
            push_num_into_deque(dq, Item(i, nums[i]));
            ans.push_back(dq.front().num);
        }
        return ans;
    }
};