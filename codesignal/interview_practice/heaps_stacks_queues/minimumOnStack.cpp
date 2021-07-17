vector<int> minimumOnStack(vector<string> operations) {
    stack<int> st, min_st;
    vector<int> ans;
    for(auto &op : operations) {
        if(op == "min") {
            ans.push_back(min_st.top());
        }
        else if(op == "pop") {
            if(min_st.top() == st.top()) {
                min_st.pop();
            }
            st.pop();
        }
        else {
            auto num = stoi(op.substr(5));
            st.push(num);
            if(min_st.empty() || min_st.top() >= num) {
                min_st.push(num);
            }
        }
    }
    return ans;
}
