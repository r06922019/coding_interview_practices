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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(q.size()) {
            int n = q.size();
            vector<int> cur_vec;
            cur_vec.reserve(n);
            while(n--) {
                TreeNode *cur_node = q.front();
                cur_vec.push_back(cur_node->val);
                q.pop();
                if(cur_node->left) q.push(cur_node->left);
                if(cur_node->right) q.push(cur_node->right);
            }
            ans.push_back(move(cur_vec));
        }
        return ans;
    }
};