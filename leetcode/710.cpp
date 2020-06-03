class Solution {
public:
    unordered_map<int, int> remapping;
    int n = 0;
    Solution(int _n, vector<int>& blacklist) {
        unordered_set<int> black_set(blacklist.begin(), blacklist.end());
        n = _n - blacklist.size();

        vector<int> to_remap;
        for(int i = n; i < _n; ++i) {
            if(black_set.find(i) == black_set.end()) {
                to_remap.push_back(i);
            }
        }

        for(int i = 0, index = 0; i < blacklist.size(); ++i) {
            int &black = blacklist[i];
            if(black < n) {
                remapping[black] = to_remap[index++];
            }
        }
    }

    int pick() {
        int picked = rand() % n;
        if(remapping.find(picked) != remapping.end())
            picked = remapping[picked];
        return picked;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */