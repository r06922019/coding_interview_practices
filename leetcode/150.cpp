class Solution
{
public:
#define ll long long
    bool is_operator(const string &s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    void do_op(stack<ll> &st, const string &op)
    {
        ll b = st.top();
        st.pop();
        ll a = st.top();
        st.pop();
        if (op == "+")
        {
            st.push(a + b);
        }
        else if (op == "-")
        {
            st.push(a - b);
        }
        else if (op == "*")
        {
            st.push(a * b);
        }
        else if (op == "/")
        {
            st.push(a / b);
        }
        else
        {
            assert(0);
        }
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<ll> st;
        for (auto &token : tokens)
        {
            if (is_operator(token))
            {
                do_op(st, token);
            }
            else
            {
                st.push((ll)stoi(token));
            }
        }
        return (int)st.top();
    }
};