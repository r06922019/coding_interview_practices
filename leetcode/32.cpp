class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        stack<pair<char, int> > st;
        for (auto c : s)
        {
            if (c == '(')
            {
                st.push({'(', 0});
            }
            else
            {
                if (st.size() && st.top().first == '(')
                {
                    auto top = st.top();
                    st.pop();
                    auto len = top.second + 2;
                    while (st.size() && st.top().first == ' ')
                    {
                        len += st.top().second;
                        st.pop();
                    }
                    if (st.size() && st.top().first == '(')
                    {
                        st.top().second += len;
                    }
                    else
                    {
                        st.push({' ', len});
                    }
                    ans = max(ans, st.top().second);
                }
                else
                {
                    st.push({')', 0});
                }
            }
        }
        return ans;
    }
};