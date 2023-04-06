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
class Solution
{
public:
    TreeNode *helper(vector<int> &inorder, int i_start, int i_end,
                     vector<int> &postorder, int j_start, int j_end,
                     unordered_map<int, int> &value_to_inorder_index)
    {
        if (i_end - i_start <= 0)
            return nullptr;
        // printf("i_start %d i_end %d j_start %d j_end %d\n", i_start, i_end, j_start, j_end);
        const int &root_val = postorder[j_end - 1];
        const int &inorder_index = value_to_inorder_index[root_val];
        // printf("root %d in_index = %d\n", root_val, inorder_index);
        TreeNode *node = new TreeNode(root_val);
        // printf("left");
        node->left = helper(inorder, i_start, inorder_index,
                            postorder, j_start, j_start + (inorder_index - i_start),
                            value_to_inorder_index);
        // printf("right");
        node->right = helper(inorder, inorder_index + 1, i_end,
                             postorder, j_end - 1 - (i_end - (inorder_index + 1)), j_end - 1,
                             value_to_inorder_index);
        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> value_to_inorder_index;
        int n = inorder.size();
        for (int i = 0; i < n; ++i)
        {
            value_to_inorder_index[inorder[i]] = i;
        }
        return helper(inorder, 0, n, postorder, 0, n,
                      value_to_inorder_index);
    }
};