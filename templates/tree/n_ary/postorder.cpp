/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<pair<Node *, int>> st; // node, # of traversed children
        if(root) st.push({root, -1});
        while(st.size()) {
            auto &top = st.top();
            auto &node = top.first;
            auto &num_traversed = top.second;
            if(num_traversed == -1) {
                num_traversed = 0;
            }
            else if(num_traversed < node->children.size()) {
                ++num_traversed;
                st.push({node->children[num_traversed-1], -1});
            }
            else {
                ans.push_back(node->val);
                st.pop();
            }
        }
        return ans;
    }

    /*
    void traverse(Node *root, vector<int> &ans) {
        if(root == nullptr) return;
        for(auto &n : root->children)
            traverse(n, ans);
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
    */
};