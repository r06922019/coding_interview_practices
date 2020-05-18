class Solution {
public:
    int find_group(vector<int> &parent, int cur) {
        int group = parent[cur];
        if(group != cur)
            group = find_group(parent, group);
        parent[cur] = group;
        return group;
    }

    bool merge_group(vector<int> &parent, vector<int> &group_count, int a, int b) {
        int a_group = find_group(parent, a);
        int b_group = find_group(parent, b);

        bool ret = a_group != b_group;
        if(a_group < b_group) {
            parent[b_group] = a_group;
            group_count[a_group] += group_count[b_group];
            group_count[b_group] = 0;
        }
        else if(b_group < a_group) {
            parent[a_group] = b_group;
            group_count[b_group] += group_count[a_group];
            group_count[a_group] = 0;
        }

        return ret;
    }

    void init_group(int n, vector<int> &parent, vector<int> &group_count) {
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            group_count[i] = 1;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int connection_needed = n-1;
        if(connections.size() < connection_needed) return -1;

        vector<int> parent(n, 0), group_count(n, 0);
        init_group(n, parent, group_count);

        int count = 0;
        for(vector<int> &conn : connections) {
            int &a = conn[0], &b = conn[1];
            if(merge_group(parent, group_count, a, b)) {
                ++count;
            }
        }
        return connection_needed-count;
    }
};