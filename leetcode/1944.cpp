class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans;
        reverse(heights.begin(),heights.end());
        stack<int> st;
        for(int &h : heights) {
            ans.push_back(0);
            while(st.size() && st.top() < h) {
                ++ans.back();
                st.pop();
            }
            if(st.size())
                ++ans.back();
            st.push(h);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};