class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for(int i = 0; i < n; ++i) {
            int &cur_temp = temperatures[i];
            while(st.size() && temperatures[st.top()] < cur_temp) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};