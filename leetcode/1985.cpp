class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](const string &a, const string &b) { return a.size() > b.size() || (a.size() == b.size() && a > b); };
        // sort(nums.begin(), nums.end(), comp);
        // return nums[k-1];
        priority_queue<string, vector<string>, decltype(comp)> pq(comp);
        for(const auto &num : nums) {
            pq.push(num);
            while(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};