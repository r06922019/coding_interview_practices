class Solution {
public:
    int findKthLargest(vector<int>& nums, int start, int end, int k) {
        // find x s.t. at most k-1 numbers > x in array
        if(end-start == k) return *min_element(nums.begin()+start, nums.begin()+end);

        int x = nums[end-1];
        int lef_size = 0;
        for(int i = start; i < end; ++i) {
            if(nums[i] > x) {
                swap(nums[i], nums[start+lef_size]);
                ++lef_size;
            }
        }
        swap(nums[end-1], nums[start+lef_size]);

        // left_size elements , x , ....
        if(lef_size >= k) {
            return findKthLargest(nums, start, start+lef_size, k);
        }
        else if(lef_size == k-1) {
            return nums[start+lef_size];
        }
        else {
            // start+lef_size < k-1
            // => start+lef_size+1 < 1
            // skip left_size+1 elements
            return findKthLargest(nums, start+lef_size+1, end, k-(lef_size+1));
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // auto comp = [](const int a, const int b) { return a > b; };
        // priority_queue<int, vector<int>, decltype(comp)> pq(comp); // min pq uses greater comp
        // for(auto &num : nums) {
        //     pq.push(num);
        //     while(pq.size() > k) pq.pop();
        // }
        // return pq.top();
        return findKthLargest(nums, 0, nums.size(), k);
    }
};
