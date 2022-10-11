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
    int goodNodes(TreeNode *root, TreeNode *cur_max)
    {
        if (root == nullptr)
            return 0;

        // traverse self
        int count = 0;
        if (cur_max == nullptr || cur_max->val <= root->val)
        {
            ++count;
            cur_max = root;
        }
        // traverse children
        return count + goodNodes(root->left, cur_max) +
               goodNodes(root->right, cur_max);
    }

    int goodNodes(TreeNode *root)
    {
        return goodNodes(root, nullptr);
    }
};

/*
class Solution {
public:
    void goodNodes(TreeNode* root, int &count, multiset<int> &visited) {
        if(root == nullptr) return;

        // traverse self
        if(visited.empty() || *visited.rbegin() <= root->val) {
            ++count;
        }

        // push self
        visited.insert(root->val);

        // traverse children
        goodNodes(root->left, count, visited);
        goodNodes(root->right, count, visited);

        // pop self
        visited.erase(visited.find(root->val));
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        multiset<int> visited;
        goodNodes(root, count, visited);
        return count;
    }
};
*/