int kthLargestElement(vector<int> nums, int k) {
    auto comp = [](const int &a, const int &b) { return a > b; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    // pq with larger is a min pq
    for(auto &num : nums) {
        pq.push(num);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}
