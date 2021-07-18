/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* merge_trees(TreeNode *a, TreeNode *b) {
        if(a == nullptr && b == nullptr) return nullptr;
        if(a != nullptr && b == nullptr) return a;
        if(a == nullptr && b != nullptr) return b;

        // // always pick a as the root
        // if(a->val < b->val) {
        //     a->right = merge_trees(a->right, b);
        // }
        // else {
        //     a->left = merge_trees(a->left, b);
        // }

        if(a->right == nullptr) {
            a->right = b;
            return a;
        }

        // find rightmost child of a
        TreeNode *rightmost_child_of_a = a, *parent = nullptr;
        while(rightmost_child_of_a->right) {
            parent = rightmost_child_of_a;
            rightmost_child_of_a = rightmost_child_of_a->right;
        }
        // no need to check if parent isn't null since it would return at line 27
        // rightmost_child_of_a have no right child
        parent->right = rightmost_child_of_a->left; // so taking the left one can do
        rightmost_child_of_a->left = a;
        rightmost_child_of_a->right = b;
        return rightmost_child_of_a;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else
            root = merge_trees(root->left, root->right);
        return root;
    }
};