// https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook
#include <vector>
#include <random>
#include <algorithm>
#include <cstdio>

using namespace std;

#define TEST_INDEX 0
#define ITERATIONS 10000

// find first element that >= x
// int binary_search0(vector<int> &arr, int l, int r, int x) {
//     if(l == r) return l;
//     int mid = l + (r-l)/2;
//     if(x <= arr[mid])
//         return binary_search0(arr, l, mid, x);
//     else
//         return binary_search0(arr, mid+1, r, x);
// }

int binary_search0(vector<int> &arr, int l, int r, int x) {
    while(l < r) {
        int mid = l + (r-l)/2;
        if(x <= arr[mid]) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    return l;
}

// find last element that < x
int binary_search1(vector<int> &arr, int l, int r, int x) {
    int index = binary_search0(arr, l, r, x);
    return index-1;
}

// find last element that <= x -> search at right half
// mid is right-preferred, use x >= mid
int binary_search2(vector<int> &arr, int l, int r, int x) {
    while(l < r) {
        int mid = l + (r-l+1)/2;
        if(x >= arr[mid]) {
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    return l;
}

// find first element that > x
int binary_search3(vector<int> &arr, int l, int r, int x) {
    return binary_search2(arr, l, r, x)+1;
}

bool test_function(vector<int> &arr, int target) {
    int ans = -1, ret = -1;
    if(TEST_INDEX == 0) {
        ret = binary_search0(arr, 0, arr.size()-1, target);
        for(int j = 0; j < arr.size() && arr[j] < target; ++j) {
            ans = j;
        }
        ++ans;
    }
    else if(TEST_INDEX == 1) {
        ret = binary_search1(arr, 0, arr.size()-1, target);
        for(int j = 0; j < arr.size() && arr[j] < target; ++j) {
            ans = j;
        }
    }
    else if(TEST_INDEX == 2) {
        ret = binary_search2(arr, 0, arr.size()-1, target);
        for(int j = 0; j < arr.size() && arr[j] <= target; ++j) {
            ans = j;
        }
    }
    else if(TEST_INDEX == 3) {
        ret = binary_search3(arr, 0, arr.size()-1, target);
        for(int j = 0; j < arr.size() && arr[j] <= target; ++j) {
            ans = j+1;
        }
    }
    return ans == ret;
}


int main(int argc, char const *argv[]) {
    int n = 1e4, k = 1e2;
    vector<int> arr;
    arr.reserve(n);
    srand(time(NULL));
    for(int i = 0; i < n; ++i) {
        arr.push_back(rand() % k);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < ITERATIONS; ++i) {
        int target = rand() % k;
        if(!test_function(arr, target)) {
            for(int j = 0; j < n; ++j) {
                printf("arr[%d] = %d\n", j, arr[j]);
            }
            printf("target = %d\n", target);
            assert(0);
        }
    }
    return 0;
}
