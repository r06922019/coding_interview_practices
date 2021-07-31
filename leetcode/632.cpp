class Item {
public:
    int item_index = 0;
    int vec_index = 0;
    vector<int> vec;
    Item(int _item_index, int _vec_index, vector<int> &_v) {
        item_index = _item_index;
        vec = _v;
        vec_index = _vec_index;
    }

    int pop_front() {
        if(has_next()) {
            ++vec_index;
            return vec[vec_index-1];
        }
        assert(0);
        return -1;
    }

    int get_front() const {
        if(has_next()) {
            return vec[vec_index];
        }
        assert(0);
        return -1;
    }

    bool has_next() const {
        return (vec_index < vec.size());
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        auto comp = [](const Item &a, const Item &b) {
            return a.get_front() > b.get_front();
        };

        priority_queue<Item, vector<Item>, decltype(comp)> pq(comp);
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            auto &vec = nums[i];
            if(vec.size())
                pq.push({i, 0, vec});
        }

        vector<int> ans;
        deque<pair<int, int>> deq;
        unordered_map<int, int> visited;
        while(pq.size()) {
            while(pq.size() && visited.size() < n) {
                auto top = pq.top();
                pq.pop();
                ++visited[top.item_index];
                // printf("pushing {%d, %d}\n", top.item_index, top.get_front());
                deq.push_back({top.item_index, top.pop_front()});
                if(top.has_next()) {
                    pq.push(top);
                }
            }
            // pop excess
            while(deq.size() && visited.size() == n && visited[deq.front().first] > 1) {
                --visited[deq.front().first];
                deq.pop_front();
            }

            if(visited.size() == n) {
                vector<int> cur = {deq.front().second, deq.back().second};
                // printf("trying {%d, %d}\n", cur[0], cur[1]);
                if( ans.empty() || (cur[1]-cur[0]) < (ans[1] - ans[0]) ) {
                    ans = cur;
                }
            }

            while(visited.size() == n) {
                auto front = deq.front();
                deq.pop_front();
                --visited[front.first];
                if(visited[front.first] == 0) {
                    visited.erase(front.first);
                }
            }
        }
        return ans;
    }
};