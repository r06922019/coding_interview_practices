class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> smaller(n, 0);

        vector<vector<int>> to_sort;
        for(int i = 0; i < nums.size(); ++i) {
            to_sort.push_back({nums[i], i});
        }

        merge_sort(to_sort, 0, n, smaller);
        return smaller;
    }

    void merge_sort(vector<vector<int>> &to_sort, int start, int end, vector<int> &smaller) {
        if((end-start) <= 1) {
            return ;
        }

        int mid = start + (end-start)/2;
        merge_sort(to_sort, start, mid, smaller);
        merge_sort(to_sort, mid, end, smaller);

        // merge [start, mid) [mid, end)
        vector<vector<int>> merged;
        int i = start, j = mid;
        while(i < mid || j < end) {
            if(j == end || (i < mid && to_sort[i][0] <= to_sort[j][0])) {
                // get from left part
                smaller[to_sort[i][1]] += j - mid;
                merged.push_back(to_sort[i]);
                ++i;
            }
            else { // get from right part
                merged.push_back(to_sort[j]);
                ++j;
            }
        }

        // move
        for(int i = 0; i < merged.size(); ++i) {
            to_sort[start+i] = merged[i];
        }
        return ;
    }
};

