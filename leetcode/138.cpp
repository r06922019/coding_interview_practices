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
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        for (Node *cur = head; cur;)
        {
            Node *dup = new Node(cur->val), *next = cur->next;
            cur->next = dup;
            dup->next = next;
            cur = next;
        }

        for (Node *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;

        Node *dummy = new Node(0);
        for (Node *cur = head, *d_head = dummy; cur; cur = cur->next)
        {
            Node *next = cur->next, *next_next = next->next;

            next->next = nullptr;
            d_head->next = next;
            d_head = next;
            cur->next = next_next;
        }

        Node *ret = dummy->next;
        delete dummy;
        return ret;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> node_mapping;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        if (node_mapping.find(head) != node_mapping.end())
            return node_mapping[head];

        Node *new_node = new Node(head->val);
        node_mapping[head] = new_node;
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
};