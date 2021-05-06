// https://cses.fi/problemset/task/1139/
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX = 2*1e5;
int ans[MAX] = {0};
int colors[MAX] = {0};
unordered_set<int> child_list[MAX];

void traverse_tree(int cur) {
    unordered_set<int> &cur_list = child_list[cur];
    if(cur_list.size()) {
        for(auto &child : cur_list) {
            child_list[child].erase(cur);
        }
        for(auto &child : cur_list) {
            traverse_tree(child);
        }
    }

}

unordered_set<int> *update_ans(int cur, int parent) {
    unordered_set<int> &cur_list = child_list[cur];
    cur_list.erase(parent);
    if(cur_list.size()) {
        int n = cur_list.size();
        vector<unordered_set<int> *> tmp_color_sets;
        int max_index = 0;
        for(auto &child : cur_list) {
            tmp_color_sets.push_back(update_ans(child, cur));
        }
        for(int i = 1; i < n; ++i)
            if(tmp_color_sets[i]->size() > tmp_color_sets[max_index]->size())
                max_index = i;
        unordered_set<int> *max_size_set = tmp_color_sets[max_index];
        for(int i = 0; i < n; ++i) {
            if(i != max_index) {
                for(auto &c : *tmp_color_sets[i]) {
                    max_size_set->insert(c);
                }
                delete tmp_color_sets[i];
            }
        }
        max_size_set->insert(colors[cur]);
        ans[cur] = max_size_set->size();
        return max_size_set;
    }
    else {
        ans[cur] = 1;
        return new unordered_set<int>({colors[cur]});
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &colors[i]);
    }

    for (int i = 0; i < n-1; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a; --b;
        child_list[a].insert(b);
        child_list[b].insert(a);
    }

    // traverse tree to get edge direction
    // traverse_tree(0);

    // update ans
    unordered_set<int> *tmp = update_ans(0, 0);
    delete tmp;

    // output
    printf("%d", ans[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", ans[i]);
    }
    puts("");

    return 0;
}