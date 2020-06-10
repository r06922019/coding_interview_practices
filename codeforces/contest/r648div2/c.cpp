#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    vector<int> a(n+1, 0), b(n+1, 0);
    for(int i = 0, tmp; i < n; ++i) {
        scanf("%d", &tmp);
        a[tmp] = i;
    }
    for(int i = 0, tmp; i < n; ++i) {
        scanf("%d", &tmp);
        b[tmp] = i;
    }

    int ans = 0;
    vector<int> counts(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        int diff = a[i] - b[i];
        if(diff < 0) {
            diff += n;
        }
        ++counts[diff];
        ans = max(ans, counts[diff]);
    }
    printf("%d\n", ans);
    return 0;
}