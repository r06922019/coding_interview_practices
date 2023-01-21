class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int start = 0;
        stack<int> st;
        unordered_set<int> visited;
        st.push(start), visited.insert(start);
        while (st.size())
        {
            auto cur = st.top();
            st.pop();
            for (auto neigh : rooms[cur])
            {
                if (visited.find(neigh) == visited.end())
                {
                    st.push(neigh), visited.insert(neigh);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};