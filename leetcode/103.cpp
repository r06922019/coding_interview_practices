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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int level = 0;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(q.size()) {
            int q_size = q.size();
            vector<int> cur_ans;
            while(q_size--) {
                auto cur = q.front();
                q.pop();
                cur_ans.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(level % 2 == 1) {
                reverse(cur_ans.begin(), cur_ans.end());
            }
            ans.push_back(cur_ans);
            ++level;
        }
        return ans;
    }
};