/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> node_mapping;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(node_mapping.find(head) != node_mapping.end())
            return node_mapping[head];

        Node *new_node = new Node(head->val);
        node_mapping[head] = new_node;
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
};