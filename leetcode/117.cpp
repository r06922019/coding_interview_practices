/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        Node *cur = root, *next_head = nullptr, *next_start = nullptr;
        while(cur) {
            while(cur) {
                if(cur->left) {
                    if(next_start == nullptr) {
                        next_start = next_head = cur->left;
                    }
                    else {
                        next_head->next = cur->left;
                        next_head = cur->left;
                    }
                }
                if(cur->right) {
                    if(next_start == nullptr) {
                        next_start = next_head = cur->right;
                    }
                    else {
                        next_head->next = cur->right;
                        next_head = cur->right;
                    }
                }
                cur = cur->next;
            }
            cur = next_start;
            next_head = next_start = nullptr;
        }
        /*
        queue<Node *> q;
        q.push(root);
        while(q.size()) {
            int q_size = q.size();
            Node *next = nullptr;
            while(q_size--) {
                Node *cur = q.front();
                q.pop();
                cur->next = next;
                next = cur;
                if(cur->right) {
                    q.push(cur->right);
                }
                if(cur->left) {
                    q.push(cur->left);
                }
            }
        }
        */
        return root;
    }
};