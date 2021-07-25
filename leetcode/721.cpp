class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, vector<int>> adj_lists;
        unordered_map<int, vector<string>> index_to_emails;
        unordered_map<string, int> email_to_index;
        int n = accounts.size();
        for(int i = 0; i < n; ++i) {
            bool name_skipped = false;
            vector<string> vec;
            for(auto &email : accounts[i]) {
                if(!name_skipped) {
                    name_skipped = true;
                    continue;
                }
                if(email_to_index.find(email) != email_to_index.end()) {
                    adj_lists[i].push_back(email_to_index[email]);
                    adj_lists[email_to_index[email]].push_back(i);
                }
                email_to_index[email] = i;
                vec.push_back(email);
            }
            index_to_emails[i] = vec;
        }

        vector<bool> visited(n, false);
        unordered_map<int, set<string>> ans_set;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                set<string> s;
                stack<int> st;
                st.push(i);
                visited[i] = true;
                for(auto &email : index_to_emails[i]) {
                    s.insert(email);
                }
                while(st.size()) {
                    int top = st.top();
                    st.pop();
                    for(auto &next : adj_lists[top]) {
                        if(!visited[next]) {
                            visited[next] = true;
                            for(auto &email : index_to_emails[next]) {
                                s.insert(email);
                            }
                            st.push(next);
                        }
                    }
                }
                ans_set[i] = s;
            }
        }

        vector<vector<string>> ans;
        for(auto &p : ans_set) {
            ans.push_back({accounts[p.first][0]});
            auto &emails = p.second;
            for(auto &email : emails) {
                ans.back().push_back(email);
            }
        }
        return ans;
    }
};