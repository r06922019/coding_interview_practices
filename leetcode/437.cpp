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

    void traverse(TreeNode *root, vector<TreeNode *> &nodes) {
        if(root == nullptr) return ;
        nodes.push_back(root);
        for(auto &n : {root->left, root->right}) {
            traverse(n, nodes);
        }
    }

    int pathSumHelper(TreeNode* root, long long int targetSum) {
        if(root == nullptr) return 0;
        int ret = 0;
        targetSum -= root->val;
        if(targetSum == 0) {
            ++ret;
        }
        for(auto &n : {root->left, root->right}) {
            ret += pathSumHelper(n, targetSum);
        }
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<TreeNode *> start_nodes;
        traverse(root, start_nodes);
        int ans = 0;
        for(auto &start_node : start_nodes) {
            ans += pathSumHelper(start_node, targetSum);
        }
        return ans;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        helper(root, 0, targetSum, ans, true);
        return ans;
    }

    void helper(TreeNode* root, long long int curSum,
                long long int targetSum, int &ans, bool is_start) {
        if(root == nullptr) return;
        curSum += root->val;
        if(curSum == targetSum) {
            ++ans;
        }
        for(auto &node : {root->left, root->right}) {
            helper(node, curSum, targetSum, ans, false);
            if(is_start)
                helper(node, 0, targetSum, ans, true);
        }
        return;
    }
};