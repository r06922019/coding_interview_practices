# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.ans = []

        def helper(root: Optional[TreeNode]) -> Optional[tuple[int, int]]:
            if root is None:
                return None
            min_val = max_val = val = root.val
            if root.left:
                min_val, left_max_val = helper(root.left)
                self.ans.append(val - left_max_val)
            if root.right:
                right_min_val, max_val = helper(root.right)
                self.ans.append(right_min_val - val)
            return min_val, max_val
        helper(root)
        return min(self.ans)
