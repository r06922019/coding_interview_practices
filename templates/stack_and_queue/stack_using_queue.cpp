class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> in_st, out_st;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in_st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int num = out_st.top();
        out_st.pop();
        return num;
    }

    /** Get the front element. */
    int peek() {
        if(out_st.empty()) {
            while(in_st.size()) {
                out_st.push(in_st.top());
                in_st.pop();
            }
        }
        return out_st.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in_st.empty() && out_st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */