class MinStack {
    stack<int> st, min_st;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        if(min_st.empty() || min_st.top() >= x)
            min_st.push(x);
    }

    void pop() {
        if(min_st.size() && min_st.top() == st.top())
            min_st.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */