#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> all_nums;
int arr[100000];

long long int solve() {
    int n, sum_of_pos_nums = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] > 0)
            sum_of_pos_nums += arr[i];
    }

    int max_ = ceil(sqrt(sum_of_pos_nums));
    for(int i = all_nums.size(); i <= max_; ++i) {
        all_nums.push_back(i*i);
    }

    long long int count = 0;
    int acc_sum = 0, cur_min_sum = 0;
    unordered_map<int, int> sum_counts = {{0, 1}};

    for(int i = 0; i < n; ++i) {
        acc_sum += arr[i];
        cur_min_sum = min(cur_min_sum, acc_sum);
        for(int &num : all_nums) {
            int target = acc_sum - num;
            if(sum_counts.find(target) != sum_counts.end()) {
                count += sum_counts[target];
            }
            else if(target < cur_min_sum) {
                break;
            }
        }
        ++sum_counts[acc_sum];
    }
    return count;
}


int main(void) {
    // for(int i = 0; i <= 3163; ++i) // 10^3.5 = 3162
    //     all_nums.push_back(i*i);

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}