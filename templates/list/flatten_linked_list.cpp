/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        stack<Node *> st;
        Node *cur = head;
        while(cur->child || cur->next || st.size()) {
            if(cur->child) {
                st.push(cur->next);
                cur->next = cur->child;
                cur->child = nullptr;
            }
            else if(cur->next) {
                cur->next->prev = cur;
                cur = cur->next;
            }
            else {
                cur->next = st.top();
                st.pop();
            }
        }
        return head;
    }
};