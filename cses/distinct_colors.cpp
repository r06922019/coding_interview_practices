// https://cses.fi/problemset/task/1139/
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX = 2*1e5;
int ans[MAX] = {0};
int colors[MAX] = {0};
vector<int> child_list[MAX];

unordered_set<int> *update_ans(int cur, int parent) {
    vector<int> &cur_list = child_list[cur];
    if(cur_list.size()) {
        int n = cur_list.size();
        vector<unordered_set<int> *> tmp_color_sets(n, nullptr);
        int max_index = -1;
        for(int i = 0; i < n; ++i) {
            if(cur_list[i] != parent)
                tmp_color_sets[i] = update_ans(cur_list[i], cur);
        }
        for(int i = 0; i < n; ++i)
            if(cur_list[i] != parent && (max_index == -1 || tmp_color_sets[i]->size() > tmp_color_sets[max_index]->size()))
                max_index = i;
        unordered_set<int> *max_size_set = tmp_color_sets[max_index];
        for(int i = 0; i < n; ++i) {
            if(i != max_index && cur_list[i] != parent) {
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
        child_list[a].push_back(b);
        child_list[b].push_back(a);
    }

    // update ans
    delete update_ans(0, 0);

    // output
    printf("%d", ans[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", ans[i]);
    }
    puts("");

    return 0;
}