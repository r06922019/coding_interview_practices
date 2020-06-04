class Solution {
public:
    bool is_similar(string &a, string &b) {
        int diff = 0;
        for(int i = 0; i < a.size() && diff <= 2; ++i) {
            if(a[i] != b[i])
                ++diff;
        }
        return diff <= 2;
    }

    // union-find based
    int find_group(vector<int> &group, int i) {
        if(i != group[i]) {
            group[i] = find_group(group, group[i]);
        }
        return group[i];
    }

    void merge_group(vector<int> &group, int i, int j, int &count) {
        int group_i = find_group(group, i);
        int group_j = find_group(group, j);
        if(group_i != group_j) --count;
        group[group_j] = group_i;
    }

    vector<string> gen_neighbors(string &s) {
        int w = s.size();
        vector<string> ret;
        for(int i = 0; i < w; ++i) {
            for(int j = i+1; j < w; ++j) {
                if(s[i] != s[j]) {
                    swap(s[i], s[j]);
                    ret.push_back(s);
                    swap(s[i], s[j]);
                }
            }
        }

        return ret;
    }

    int numSimilarGroups(vector<string>& A) {
        int n = A.size(), w = A[0].size();
        int count = n;
        vector<int> group(n, 0);

        // O(N)
        for(int i = 0; i < n; ++i) {
            group[i] = i;
        }

        // N^2 * W or N * W^3
        // if(n < w*w) {
        if(true) {
            for(int i = 0; i < n; ++i) {
                for(int j = i+1; j < n; ++j) {
                    if(is_similar(A[i], A[j])) {
                        merge_group(group, i, j, count);
                    }
                }
            }
        }
        else {
            unordered_map<string, vector<int>> str_to_indexs;
            for(int i = 0; i < n; ++i) {
                str_to_indexs[A[i]].push_back(i);
            }

            // merge same first
            for(auto &it : str_to_indexs) {
                int i = it.second.front();
                for(auto &j : it.second) {
                    merge_group(group, i, j, count);
                }
            }

            for(int i = 0; i < n; ++i) {
                for(string &neighbor : gen_neighbors(A[i])) {
                    for(auto &j : str_to_indexs[neighbor]) {
                        merge_group(group, i, j, count);
                    }
                }
            }
        }

        return count;
    }

    /*
    // dfs takes N^2 in worse case ?
    void dfs(int start, vector<vector<int>> &adj_list, vector<bool> &visited) {
        stack<int> s;
        s.push(start);
        visited[start] = true;
        while(s.size()) {
            int cur = s.top();
            s.pop();
            for(auto &n : adj_list[cur]) {
                if(!visited[n]) {
                    s.push(n);
                    visited[n] = true;
                }
            }
        }
        return ;
    }

    int numSimilarGroups(vector<string>& A) {
        vector<vector<int>> adj_list(A.size(), vector<int>());
        // N^2 * W
        for(int i = 0; i < A.size(); ++i) {
            for(int j = i+1; j < A.size(); ++j) {
                if(is_similar(A[i], A[j])) {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        int num_of_groups = 0;
        vector<bool> visited(A.size(), false);
        for(int i = 0; i < A.size(); ++i) {
            if(!visited[i]) {
                ++num_of_groups;
                // dfs from i
                dfs(i, adj_list, visited);
            }
        }
        return num_of_groups;
    }
    */
};