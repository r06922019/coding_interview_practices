class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n, INT_MIN);
        scores[0] = nums[0];
        deque<int> deq;
        deq.push_back(0);
        for(int i = 1; i < n; ++i) {
            while(deq.size() && deq.front() < i-k) {
                deq.pop_front();
            }
            scores[i] = scores[deq.front()] + nums[i];
            while(deq.size() && scores[deq.back()] <= scores[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            // for(int j = 1; j <= k && i - j >= 0; ++j) {
            //     scores[i] = max(scores[i], scores[i-j] + nums[i]);
            // }
        }
        return scores.back();
    }
};