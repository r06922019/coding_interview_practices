#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;

    // printf("l = %d, r = %d\n", l,r);
    // for(int i = l; i <= r; ++i) {
    //     printf("%d ", nums[i]);
    // }
    // puts("");

    int k = l + rand() % (r - l);
    const int pivot = nums[k];
    // printf("pivot = %d\n", pivot);
    swap(nums[k], nums[r]);

    int i = l;
    for (int j = l; j < r; ++j)
    {
        if (nums[j] <= pivot)
        {
            // printf("swapping nums[%d] %d, nums[%d], %d\n", i, nums[i], j, nums[j]);
            swap(nums[i++], nums[j]);
        }
    }

    swap(nums[i], nums[r]);
    // printf("i = %d\n", i);
    quick_sort(nums, l, i - 1);
    quick_sort(nums, i + 1, r);
}

void merge_sort(vector<int> &nums, int start, int end)
{
    if (end - start <= 1)
        return;

    int mid = start + ((end - start) >> 1);
    merge_sort(nums, start, mid);
    merge_sort(nums, mid, end);

    vector<int> tmp;
    int l = start, r = mid;
    while (l < mid || r < end)
    {
        if (r >= end || (l < mid && nums[l] < nums[r]))
        {
            tmp.push_back(nums[l]);
            ++l;
        }
        else
        {
            tmp.push_back(nums[r]);
            ++r;
        }
    }

    for (int i = start; i < end; ++i)
    {
        nums[i] = tmp[i - start];
    }
    return;
}

int main(void)
{
    vector<int> nums;
    int N = 1e3, rand_range = 1e5;

    // generate
    nums.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        nums.push_back(rand() % rand_range);
    }

    vector<int> nums1 = nums;

    merge_sort(nums, 0, N);

    sort(nums1.begin(), nums1.end());

    for (int i = 0; i < N; ++i)
    {
        if (nums[i] != nums1[i])
        {
            puts("failed");
            return 1;
        }
    }

    return 0;
}
