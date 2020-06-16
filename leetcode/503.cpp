class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int j = 0; j < 2; ++j) {
            for(int i = 0; i < n; ++i) {
                int &num = nums[i];
                while(st.size() && nums[st.top()] < num) {
                    if(ans[st.top()] == -1)
                        ans[st.top()] = num;
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};