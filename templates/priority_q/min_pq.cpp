class Solution {
public:
    int thirdMax(vector<int>& nums) {
        auto comp = [](const int &a, const int &b) { return a > b; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        unordered_set<int> seen;
        for(auto &num : nums) {
            if(seen.find(num) == seen.end()) {
                seen.insert(num);
                pq.push(num);
                if(pq.size() > 3) pq.pop();
            }
        }
        if(pq.size() < 3) {
            while(pq.size() > 1) pq.pop();
        }
        return pq.top();
    }
};