std::vector<int> graphDistances(std::vector<std::vector<int>> g, int s) {
    int n = g.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(g[i][j] < 0)
                g[i][j] = 123456;
        }
    }

    vector<int> ans(g[s]);
    ans[s] = 0;
    int num_nodes_left = n-1;
    vector<bool> added(n, false);
    added[s] = true;
    while(num_nodes_left) {
        int min_index = -1;
        for(int i = 0; i < n; ++i) {
            if(!added[i] && i != s) {
                if(min_index < 0 || ans[min_index] > ans[i]) {
                    min_index = i;
                }
            }
        }
        added[min_index] = true;
        for(int j = 0; j < n; ++j) {
            if(!added[j] && ans[min_index] + g[min_index][j] < ans[j]) {
                ans[j] = ans[min_index] + g[min_index][j];
            }
        }
        --num_nodes_left;
    }

    return ans;
}
