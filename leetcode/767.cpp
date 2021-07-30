class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counter;
        for(auto &c : s) {
            ++counter[c];
        }
        char max_char = 'a';
        int max_count = 0;
        for(auto &p : counter) {
            if(p.second > max_count) {
                max_char = p.first;
                max_count = p.second;
            }
        }
        if((max_count+max_count-1) > s.size()) return "";
        vector<pair<int, char>> vec;
        for(auto &p : counter) {
            vec.push_back({p.second, p.first});
        }
        sort(vec.begin(), vec.end(), [](const pair<int, char> &a, const pair<int, char> &b) {
            return (a.first > b.first) || ((a.first == b.first) && (a.second > b.second));
        });

        string ans(s.size(), '0');
        int index = 0;
        for(int i = 0; i < s.size(); i += 2) {
            ans[i] = vec[index].second;
            --vec[index].first;
            if(vec[index].first == 0)
                ++index;
        }
        for(int i = 1; i < s.size(); i += 2) {
            ans[i] = vec[index].second;
            --vec[index].first;
            if(vec[index].first == 0)
                ++index;
        }
        return ans;
    }
};