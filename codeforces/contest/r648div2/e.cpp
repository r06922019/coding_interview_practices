#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cassert>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    vector<long long int> nums;
    long long int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &tmp);
        nums.push_back(tmp);
    }
    long long int ans = 0;
    for (auto &a : nums) {
        for (auto &b : nums) {
            for (auto &c : nums) {
                ans = max(ans, a | b | c);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
at least max(1,k−2) num have i-th bit set
if k == 1,2,3 -> at least 1 num have i-th bit set -> bitwise-or
always better to have k == 3

for k > 3, max(1, k-2) => k-2
at least k-2 nums have i-th bit set
-> at most 2 nums have i-th bit unset
choose any 3 elements will achieve the same result (k == 3)
because at most 2 numbers have i-th bit unset, what is present in the k>3 set answer
will also be in the subset of k == 3

*/