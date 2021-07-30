class MedianFinder {
public:
    /** initialize your data structure here. */
    constexpr static auto comp = [](const int &a, const int &b){return a > b;};
    priority_queue<int, vector<int>, decltype(comp)> min_pq; // stores number that are larger than the median
    priority_queue<int> max_pq; // stores number that are larger than the median

    MedianFinder() : min_pq(comp) {

    }

    void addNum(int num) {
        if(min_pq.size() < max_pq.size()) {
            max_pq.push(num);
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else {
            min_pq.push(num);
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    double findMedian() {
        int total_size = min_pq.size() + max_pq.size();
        double ans = 0;
        if(total_size % 2 == 0) {
            ans += min_pq.top() + max_pq.top();
            ans /= 2;
        }
        else {
            if(min_pq.size() < max_pq.size()) {
                ans = max_pq.top();
            }
            else {
                ans = min_pq.top();
            }
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */