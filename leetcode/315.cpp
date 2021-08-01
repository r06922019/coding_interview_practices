class Solution {
public:
    void merge_sort(vector<int> &nums, vector<int> &indexs, int start, int end, vector<int> &ans) {
        if(end-start <= 1) return ;

        int mid = start + ((end-start) >> 1);
        merge_sort(nums, indexs, start, mid, ans);
        merge_sort(nums, indexs, mid, end, ans);

        vector<int> tmp;
        int l = start, r = mid;
        while(l < mid || r < end) {
            if(r >= end || (l < mid && nums[indexs[l]] <= nums[indexs[r]])) {
                ans[indexs[l]] += r-mid;
                tmp.push_back(indexs[l]);
                ++l;
            }
            else {
                tmp.push_back(indexs[r]);
                ++r;
            }
        }
        for(int i = start; i < end; ++i) {
            indexs[i] = tmp[i-start];
        }
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> indexs(n, 0);
        for(int i = 0; i < n; ++i) {
            indexs[i] = i;
        }
        vector<int> ans(n, 0);
        merge_sort(nums, indexs, 0, n, ans);
        return ans;
    }
};