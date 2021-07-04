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

// iterative, constant space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur = head;
        while(cur) {
            Node *next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }

        cur = head;
        while(cur) {
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        Node *dummy = new Node(-1);
        Node *new_cur = dummy;
        cur = head;
        while(cur) {
            new_cur->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            new_cur = new_cur->next;
        }
        Node *new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};

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