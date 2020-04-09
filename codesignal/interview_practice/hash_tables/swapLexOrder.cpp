// swapLexOrder
int find_group(unordered_map<int, int> &index_to_group, int query) {
    if(index_to_group.find(query) == index_to_group.end())
        return -1;

    if(index_to_group[query] == query)
        return query;

    int group = find_group(index_to_group, index_to_group[query]);
    index_to_group[query] = group;
    return group;
}

void merge_group(unordered_map<int, int> &index_to_group, vector<int> &groups_to_merge) {
    int g0 = find_group(index_to_group, groups_to_merge[0]);
    int g1 = find_group(index_to_group, groups_to_merge[1]);
    if(g0 != g1) {
        index_to_group[g1] = g0;
    }
    return ;
}

std::string swapLexOrder(std::string str, std::vector<std::vector<int>> pairs) {

    // group indexs
    unordered_map<int, int> index_to_group;
    for(auto &p : pairs) {
        if(index_to_group.find(p[0]) == index_to_group.end() && index_to_group.find(p[1]) == index_to_group.end()) {
            index_to_group[p[0]] = index_to_group[p[1]] = p[0];
        }
        else {
            vector<int> groups_to_merge(p);
            for(int i = 0; i < 2; ++i) {
                if(index_to_group.find(p[i]) == index_to_group.end()) {
                    index_to_group[ p[i] ] = p[i];
                }
                else {
                    groups_to_merge[i] = index_to_group[ p[i] ];
                }
            }

            // merge group of p[0], p[1]
            merge_group(index_to_group, groups_to_merge);
        }
    }

    // groups -> vector<set<int>>
    unordered_map<int, set<int>> groups;
    for(auto &it : index_to_group) {
        const int &index = it.first;
        int group_id = find_group(index_to_group, it.second);
        groups[ group_id ].insert(index);
    }

    for(auto &it : groups) { // group -> set<int>
        set<int> &group = it.second;
        vector<char> chars;
        for(const int &index : group)
            chars.push_back(str[index-1]);

        sort(chars.rbegin(), chars.rend());
        int i = 0;
        for(const int &index : group) {
            str[index-1] = chars[i];
            ++i;
        }
    }
    return str;
}
