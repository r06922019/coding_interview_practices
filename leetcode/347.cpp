class Item {
public:
    int num, count;
    Item () {
        num = count = 0;
    }
    Item (int _num, int _count) {
        num = _num;
        count = _count;
    }
};

typedef const Item CI;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(int &num : nums) {
            ++counter[num];
        }

        // #include <functional>
        function<bool (CI, CI)> comp = [](CI &a, CI &b) { return (a.count > b.count); }; // b at top
        priority_queue<Item, vector<Item>, decltype(comp)> pq(comp);
        for(auto &it : counter) {
            pq.push(Item(it.first, it.second));
            while(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(pq.size()) {
            Item cur = pq.top();
            pq.pop();
            ans.push_back(cur.num);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};