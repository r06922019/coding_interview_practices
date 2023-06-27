class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0, n = isConnected.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ++ans;
                stack<int> st;
                st.push(i);
                visited[i] = true;
                while (st.size())
                {
                    auto cur = st.top();
                    st.pop();
                    for (int j = 0; j < n; ++j)
                    {
                        if (isConnected[cur][j] && !visited[j])
                        {
                            st.push(j);
                            visited[j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};