class Node {
public:
    int val;
    Node *next;
    Node() {
        val = -1;
        next = nullptr;
    }
    Node(int _v) {
        val = _v;
        next = nullptr;
    }
    Node(int _v, Node *_n) {
        val = _v;
        next = _n;
    }
};

class MyLinkedList {
public:
    Node *dummy = nullptr;
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new Node();
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *cur = dummy->next;
        while(cur && index) {
            cur = cur->next;
            --index;
        }
        return (cur == nullptr)? -1:cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *new_node = new Node(val, dummy->next);
        dummy->next = new_node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = dummy->next, *prev = dummy;
        while(cur) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = new Node(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0) return ;
        Node *cur = dummy->next, *prev = dummy;
        for(int i = 0; i < index && prev; ++i) {
            prev = cur;
            cur = cur->next;
        }
        if(prev)
            prev->next = new Node(val, cur);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0) return ;
        Node *cur = dummy->next, *prev = dummy;
        for(int i = 0; i < index; ++i) {
            if(cur == nullptr) return;
            prev = cur;
            cur = cur->next;
        }
        if(cur == nullptr) return;
        prev->next = cur->next;
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */