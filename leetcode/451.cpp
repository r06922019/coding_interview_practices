class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        for(char &c : s) {
            ++counter[c];
        }

        vector<pair<char, int>> items;
        for(auto &it : counter) {
            items.push_back({it.first, it.second});
        }

        sort(items.begin(), items.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second > b.second;
        });

        string ans = "";
        for(auto &p : items) {
            char &c = p.first;
            int count = p.second;
            for(int i = 0; i < count; ++i) {
                ans += c;
            }
        }
        return ans;
    }
};