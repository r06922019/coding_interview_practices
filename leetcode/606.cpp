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
    void tree2str(TreeNode *root, string &ans)
    {
        if (root == nullptr)
            return;
        ans += to_string(root->val);
        if (root->left != nullptr || root->right != nullptr)
        {
            ans += "(";
            tree2str(root->left, ans);
            ans += ")";
            if (root->right != nullptr)
            {
                ans += "(";
                tree2str(root->right, ans);
                ans += ")";
            }
        }
    }

    string tree2str(TreeNode *root)
    {
        string ans = "";
        tree2str(root, ans);
        return ans;
    }

    /*
    // easier, but many copies
    string tree2str(TreeNode* root) {
        if(root == nullptr) return "";
        string cur = to_string(root->val), left = tree2str(root->left), right = tree2str(root->right);
        if(left != "" || right != "") {
            cur += "(" + left + ")";
            if(right != "")
                cur += "(" + right + ")";
        }
        return cur;
    }
};
    */
};