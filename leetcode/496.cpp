class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> next_greater;
        for(auto &num : nums2) {
            while(st.size() && st.top() < num) {
                int top = st.top();
                st.pop();
                next_greater[top] = num;
            }
            st.push(num);
        }
        while(st.size()) {
            int top = st.top();
            st.pop();
            next_greater[top] = -1;
        }

        vector<int> ans;
        for(auto &num : nums1) {
            ans.push_back(next_greater[num]);
        }
        return ans;
    }
};