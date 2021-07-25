class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // vector<int> buf = nums;
        // merge_sort(nums, 0, nums.size(), buf);
        quick_sort(nums, 0, nums.size());
        return nums;
    }

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

    void merge_sort(vector<int> &nums, int start, int end, vector<int> &buf) {
        if(end-start <= 1) return;

        int mid = start + (end-start)/2;
        merge_sort(nums, start, mid, buf);
        merge_sort(nums, mid, end, buf);

        int l = start, r = mid, index = 0;
        while(l < mid || r < end) {
            if(r >= end || (l < mid && nums[l] <= nums[r])) {
                buf[index] = nums[l];
                ++l, ++index;
            }
            else {
                buf[index] = nums[r];
                ++r, ++index;
            }
        }
        for(int i = start; i < end; ++i) {
            nums[i] = buf[i-start];
        }
    }
};