class Item {
public:
    string str;
    int count;
    Item () {
        str = "";
        count = 0;
    }

    Item (string _s, int _c) {
        str = _s;
        count = _c;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for(auto &word : words) {
            ++counter[word];
        }

        auto comp = [](const Item &a, const Item &b) { return (a.count > b.count || (a.count == b.count && a.str < b.str)); }; // comp(a,b) -> true -> b at top
        priority_queue<Item, vector<Item>, decltype(comp)> pq(comp);

        for(auto &it : counter) {
            pq.push(Item(it.first, it.second));
            while(pq.size() > k) pq.pop();
        }

        vector<string> ans;
        while(pq.size()) {
            Item cur = pq.top();
            pq.pop();
            ans.push_back(cur.str);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};