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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode *sortedArrayToBST(const vector<int> &nums, int start, int len)
    {
        if (len == 0)
            return nullptr;
        if (len == 1)
            return new TreeNode(nums[start]);

        int mid_len = len / 2;
        int mid = start + mid_len;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, start, mid - start);
        root->right = sortedArrayToBST(nums, mid + 1, len - (mid - start) - 1);
        return root;
    }
};