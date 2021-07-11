class Solution{
public:
    long long minCost(long long _arr[], long long n) {
        auto comp = [](const long long &a, const long long &b) { return a > b; };
        priority_queue<long long, vector<long long>, decltype(comp)> pq(comp);
        for(int i = 0; i < n; ++i)
            pq.push(_arr[i]);

        long long ans = 0;
        while(pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long x = a+b;
            ans += x;
            pq.push(x);
        }
        return ans;
    }
};
