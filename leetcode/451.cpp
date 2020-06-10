typedef pair<char, int> PCI;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        for(char &c : s) {
            ++counter[c];
        }

        string ans = "";
        bool use_pq = false;
        if(use_pq) {
            function<bool (const PCI, const PCI)> comp = [](const PCI &a, const PCI &b) {
                // if true, b comes first;
                return a.second < b.second;
            };

            priority_queue<PCI, vector<PCI>, decltype(comp)> pq(comp);

            for(auto &it : counter) {
                pq.push({it.first, it.second});
            }

            while(pq.size()) {
                PCI p = pq.top();
                pq.pop();
                char &c = p.first;
                int count = p.second;
                for(int i = 0; i < count; ++i) {
                    ans += c;
                }
            }
        }
        else {
            vector<pair<char, int>> items;
            for(auto &it : counter) {
                items.push_back({it.first, it.second});
            }

            sort(items.begin(), items.end(), [](const PCI &a, const PCI &b) {
                // if true, a comes first;
                return a.second > b.second;
            });

            for(auto &p : items) {
                char &c = p.first;
                int count = p.second;
                for(int i = 0; i < count; ++i) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};