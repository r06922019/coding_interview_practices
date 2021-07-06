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
    TreeNode* helper(vector<int>& inorder, int i_start, int i_end,
                     vector<int>& preorder, int j_start, int j_end,
                    unordered_map<int, int> &val_to_inorder_index) {
        if(i_end - i_start <= 0) return nullptr;

        const int root_val = preorder[j_start];
        TreeNode *node = new TreeNode(root_val);
        const int inorder_index = val_to_inorder_index[root_val];
        int left_subtree_size = inorder_index - i_start;
        int right_subtree_size = i_end - (inorder_index+1);
        node->left = helper(inorder, i_start, i_start+left_subtree_size,
                            preorder, j_start+1, j_start+1+left_subtree_size,
                            val_to_inorder_index);
        node->right = helper(inorder, inorder_index+1, i_end,
                             preorder, j_end-right_subtree_size, j_end,
                             val_to_inorder_index);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> val_to_inorder_index;
        int n = inorder.size();
        for(int i = 0; i < n; ++i) {
            val_to_inorder_index[ inorder[i] ] = i;
        }
        return helper(inorder, 0, n, preorder, 0, n, val_to_inorder_index);
    }
};