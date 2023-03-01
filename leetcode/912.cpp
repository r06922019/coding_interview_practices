class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> buf = nums;
        merge_sort(nums, 0, nums.size(), buf);
        // quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }

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

    void merge_sort(vector<int> &nums, int start, int end, vector<int> &buf)
    {
        if (end - start <= 1)
            return;

        int mid = start + (end - start) / 2;
        merge_sort(nums, start, mid, buf);
        merge_sort(nums, mid, end, buf);

        int l = start, r = mid, index = 0;
        while (l < mid || r < end)
        {
            if (r >= end || (l < mid && nums[l] <= nums[r]))
            {
                buf[index] = nums[l];
                ++l, ++index;
            }
            else
            {
                buf[index] = nums[r];
                ++r, ++index;
            }
        }
        for (int i = start; i < end; ++i)
        {
            nums[i] = buf[i - start];
        }
    }
};