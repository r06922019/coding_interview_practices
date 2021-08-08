class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto p : piles) {
            pq.push(p);
        }
        while(k--) {
            int top = pq.top();
            pq.pop();
            top -= top/2;
            pq.push(top);
        }
        int ans = 0;
        while(pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};