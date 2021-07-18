class KthLargest {
public:
    static constexpr auto comp = [](const int a, const int b) { return a > b; };
    priority_queue<int, vector<int>, decltype(comp)> *pq;
    int k;
    KthLargest(int _k, vector<int>& nums) {
        pq = new priority_queue<int, vector<int>, decltype(comp)>(comp);
        k = _k;
        for(auto &num : nums) {
            pq->push(num);
            if(pq->size() > k) pq->pop();
        }
    }

    int add(int val) {
        pq->push(val);
        if(pq->size() > k) pq->pop();
        return pq->top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */