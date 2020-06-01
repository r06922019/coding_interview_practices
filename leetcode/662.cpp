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

    bool non_leaf(TreeNode *root) {
        return root->left || root->right;
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        // pruning on root
        while(non_leaf(root) && (root->left == nullptr || root->right == nullptr)) {
            if(root->left) root = root->left;
            else root = root->right;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 0;

        while(q.size()) {
            int q_n = q.size(), max_val = INT_MIN, min_val = INT_MAX;
            while(q_n--) {
                pair<TreeNode*, int> cur = q.front();
                q.pop();
                TreeNode* &node = cur.first;
                int &pos = cur.second;

                if(node->left) q.push({node->left, 2*pos});
                if(node->right) q.push({node->right, 2*pos+1});

                max_val = max(max_val, pos);
                min_val = min(min_val, pos);
            }
            ans = max(ans, max_val - min_val + 1);
        }

        return ans;
    }
};