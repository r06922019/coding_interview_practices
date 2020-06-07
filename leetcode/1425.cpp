class Element {
public:
    int index, value;
    Element(int _i, int _v) {
        index = _i;
        value = _v;
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // Let dp[i] be the solution for the prefix of the array that ends at index i, if the element at index i is in the subsequence.
        int ans = INT_MIN, n = nums.size();
        vector<int> dp = nums;
        deque<Element> deq;
        for(int i = 0; i < n; ++i) {
            while(deq.size() && deq.front().index + k < i) {
                deq.pop_front();
            }
            if(deq.size() && deq.front().value > 0)
                dp[i] += deq.front().value;
            ans = max(ans, dp[i]);

            while(deq.size() && deq.back().value < dp[i])
                deq.pop_back();
            deq.emplace_back(i, dp[i]);
        }
        return ans;
    }

};