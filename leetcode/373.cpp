class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> indexs;
        auto comp = [&](const vector<int> &a, const vector<int> &b) {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        int index1 = 0;
        while(indexs.size() < k && (pq.size() || index1 < nums1.size())) {
            while(pq.size() < k && index1 < nums1.size()) {
                pq.push({index1,0});
                ++index1;
            }
            auto index_pair = pq.top();
            pq.pop();
            indexs.push_back(index_pair);
            ++index_pair[1];
            if(index_pair[1] < nums2.size()) {
                pq.push(index_pair);
            }
        }
        vector<vector<int>> ans;
        for(auto &index : indexs) {
            ans.push_back({nums1[index[0]], nums2[index[1]]});
        }
        return ans;
    }
};