class Item {
public:
    int index = 0;
    vector<int> vec;
    Item(int _i, vector<int> &_v) {
        index = _i;
        vec = _v;
    }
    int pop_front() {
        int val = vec[index];
        ++index;
        return val;
    }
    int peek_front() const {
        return vec[index];
    }
    bool has_next() {
        return index < vec.size();
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [](const Item &a, const Item &b) {
            return a.peek_front() > b.peek_front();
        };

        priority_queue<Item, vector<Item>, decltype(comp)> pq(comp);
        for(auto &row : matrix) {
            pq.push(Item(0, row));
        }
        int ans = 0;
        for(int i = 0; i < k; ++i) {
            auto item = pq.top();
            pq.pop();
            ans = item.pop_front();
            if(item.has_next()) pq.push(item);
        }
        return ans;
    }
};