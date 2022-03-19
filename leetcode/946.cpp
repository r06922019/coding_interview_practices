class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        reverse(popped.begin(), popped.end());
        for (auto x : pushed)
        {
            st.push(x);
            while (st.size() && st.top() == popped.back())
            {
                st.pop();
                popped.pop_back();
            }
        }
        return st.empty();
    }
};