class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st({0});
        for (auto c : s)
        {
            if (c == '(')
            {
                st.push(0);
            }
            else
            {
                int cur = st.top();
                st.pop();
                if (cur == 0)
                    st.top() += 1;
                else
                    st.top() += cur * 2;
            }
        }
        return st.top();
    }
};