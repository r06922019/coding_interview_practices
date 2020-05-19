#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> arr;
    for(int i = 0, tmp; i < n; ++i) {
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    reverse(arr.begin(), arr.end());
    int index = 0, count = 0;
    while(index < n) {
        if(arr[index] == 1) {
            int target = 1;
            while(index < n && arr[index] == target) {
                ++index;
                ++target;
            }
            --index;
            --target;
            if(target >= k)
                ++count;
        }
        ++index;
    }
    return count;
}


int main(void) {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}