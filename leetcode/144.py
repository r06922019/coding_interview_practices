# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        return [] if root is None else [root.val]+self.preorderTraversal(root.left) + self.preorderTraversal(root.right)
        # multi liner
        ret = []

        def traverse(node: TreeNode):
            if node is None:
                return
            ret.append(node.val)
            traverse(node.left)
            traverse(node.right)
        traverse(root)
        return ret
