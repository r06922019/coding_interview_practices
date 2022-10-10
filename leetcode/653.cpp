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
    void traverseTree(TreeNode *root, int target,
                      unordered_set<int> &values, bool &result)
    {
        if (root == nullptr || result)
            return;
        if (root->left)
            traverseTree(root->left, target, values, result);
        if (values.find(target - root->val) != values.end())
            result = true;
        values.insert(root->val);
        if (root->right)
            traverseTree(root->right, target, values, result);
    }

    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> values;
        bool result = false;
        traverseTree(root, k, values, result);
        return result;
    }
};

class Solution
{
public:
    void flattenTree(TreeNode *root, vector<int> &values)
    {
        if (root == nullptr)
            return;
        if (root->left)
            flattenTree(root->left, values);
        values.push_back(root->val);
        if (root->right)
            flattenTree(root->right, values);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> values;
        flattenTree(root, values);

        int l = 0, r = values.size() - 1;
        while (l < r)
        {
            int cur_sum = values[l] + values[r];
            if (cur_sum > k)
            {
                --r;
            }
            else if (cur_sum < k)
            {
                ++l;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};