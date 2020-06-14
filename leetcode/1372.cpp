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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        find_path(root, true, ans);
        return ans;
    }

    bool is_leaf(TreeNode *node) {
        return node->left == nullptr && node->right == nullptr;
    }

    int find_path(TreeNode *root, bool parent_left_child, int &ans) {
        if(root == nullptr) return -1;
        if(is_leaf(root)) return 0;

        int left = find_path(root->left, true, ans)+1;
        int right = find_path(root->right, false, ans)+1;
        ans = max(ans, max(left, right));
        return (parent_left_child)? right:left;
    }

};