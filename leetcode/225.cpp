class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void reverse_q()
    {
        int n = q.size() - 1;
        while (n--)
        {
            auto front = q.front();
            q.pop();
            q.push(front);
        }
    }

    void push(int x)
    {
        q.push(x);
        reverse_q();
    }

    int pop()
    {
        auto front = q.front();
        q.pop();
        return front;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */