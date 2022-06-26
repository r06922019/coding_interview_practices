    int find_root(int group, unordered_map<int, int> &parent) {
        int root = parent[group];
        if(root != group) {
            root = find_root(root, parent);
        }
        parent[group] = root;
        return root;
    }

    void merge_group(int group1, int group2, unordered_map<int, int> &parent) {
        int root1 = find_root(group1, parent);
        int root2 = find_root(group2, parent);
        if(root1 != root2) {
            parent[root2] = root1;
        }
        return ;
    }