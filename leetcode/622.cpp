class MyCircularQueue {
public:
    int head, tail, capacity, cur_size;
    vector<int> q;

    MyCircularQueue(int k) {
        q.reserve(k);
        capacity = k;
        cur_size = 0;
        head = 0;
        tail = -1;
    }

    bool enQueue(int value) {
        if(!isFull()) {
            ++tail;
            if(tail == capacity) tail = 0;
            q[tail] = value;
            ++cur_size;
            return true;
        }
        return false;
    }

    bool deQueue() {
        if(!isEmpty()) {
            ++head;
            if(head == capacity) head = 0;
            --cur_size;
            return true;
        }
        return false;
    }

    int Front() {
        if(isEmpty()) return -1;
        return q[head];
    }

    int Rear() {
        if(isEmpty()) return -1;
        return q[tail];
    }

    bool isEmpty() {
        return cur_size == 0;
    }

    bool isFull() {
        return cur_size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */