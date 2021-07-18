vector<int> graphDistances(vector<vector<int>> g, int s) {
    int n = g.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(g[i][j] < 0) {
                g[i][j] = 300;
            }
        }
    }
    vector<int> ans = g[s];
    unordered_set<int> seen = {s};
    ans[s] = 0;
    while(seen.size() < n) {
        int min_target = -1;
        for(int target = 0; target < n; ++target) {
            if(seen.find(target) == seen.end()) {
                if(min_target == -1 || ans[target] < ans[min_target]) {
                    min_target = target;
                }
            }
        }
        seen.insert(min_target);
        for(int next = 0; next < n; ++next) {
            if(seen.find(next) == seen.end()) {
                ans[next] = min(ans[next],
                                ans[min_target] + g[min_target][next]);
            }
        }
    }
    return ans;
}
