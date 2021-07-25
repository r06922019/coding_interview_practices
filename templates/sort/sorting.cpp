#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &nums, int start, int end) {
    if(end - start <= 1) return ;
    int pivot_index = start + rand() % (end-start);
    swap(nums[end-1], nums[pivot_index]);
    int pivot = nums[end-1];
    int j = start;
    for(int i = start; i < end; ++i) {
        if(nums[i] < pivot) {
            swap(nums[i], nums[j]);
            ++j;
        }
    }
    swap(nums[end-1], nums[j]);
    quick_sort(nums, start, j);
    quick_sort(nums, j+1, end);
}

void merge_sort(vector<int> &nums, int start, int end) {
    if(end - start <= 1) return ;

    int mid = start + ((end-start) >> 1);
    merge_sort(nums, start, mid);
    merge_sort(nums, mid, end);

    vector<int> tmp;
    int l = start, r = mid;
    while(l < mid || r < end) {
        if(r >= end || (l < mid && nums[l] < nums[r])) {
            tmp.push_back(nums[l]);
            ++l;
        }
        else {
            tmp.push_back(nums[r]);
            ++r;
        }
    }

    for (int i = start; i < end; ++i) {
        nums[i] = tmp[i-start];
    }
    return;
}

int main(void) {
    vector<int> nums;
    int N = 1e3, rand_range = 1e5;

    // generate
    nums.reserve(N);
    for(int i = 0; i < N; ++i) {
        nums.push_back(rand() % rand_range);
    }

    vector<int> nums1 = nums;

    merge_sort(nums, 0, N);

    sort(nums1.begin(), nums1.end());

    for(int i = 0; i < N; ++i) {
        if(nums[i] != nums1[i]) {
            puts("failed");
            return 1;
        }
    }

    return 0;
}





