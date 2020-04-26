#include <bits/stdc++.h>

using namespace std;

int find_group(vector<int> &groups, unordered_map<int, int> &ranks, int i) {
    if(groups[i] == i) return i;
    int group = find_group(groups, ranks, groups[i]);
    groups[i] = group;
    return group;
}

int merge_group(vector<int> &groups, unordered_map<int, int> &ranks, int a_group, int b_group) {
    if(a_group == b_group) return ranks[b_group];
    int old_group, new_group;
    if(ranks[a_group] < ranks[b_group]) {
        old_group = a_group;
        new_group = b_group;
    }
    else {
        old_group = b_group;
        new_group = a_group;
    }
    groups[old_group] = groups[new_group];
    ranks[new_group] += ranks[old_group];
    ranks[old_group] = 0;
    return ranks[new_group];
}

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
    vector<int> ans;
    unordered_map<int, int> person_index;
    unordered_map<int, int> ranks;
    vector<int> groups;
    int num_of_people = 0;

    int max_val = 1;
    for(auto &query : queries) {
        for(int &person : query) {
            if(person_index.find(person) == person_index.end()) {
                person_index[person] = num_of_people;
                groups.push_back(num_of_people);
                ranks[num_of_people] = 1;
                ++num_of_people;
            }
        }

        int g0 = find_group(groups, ranks, person_index[query[0]]);
        int g1 = find_group(groups, ranks, person_index[query[1]]);
        if(g0 != g1) {
            max_val = max(max_val, merge_group(groups, ranks, g0, g1));
        }

        ans.push_back(max_val);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
