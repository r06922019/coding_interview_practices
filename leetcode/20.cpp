class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> lut = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        stack<char> st;
        for (auto c : s)
        {
            auto it = lut.find(c);
            if (it != lut.end())
            {
                if (st.empty() || st.top() != it->second)
                    return false;
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};