# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return root
        if root.left != None:
            root.left = self.pruneTree(root.left)
        if root.right != None:
            root.right = self.pruneTree(root.right)

        if root.left == None and root.right == None and root.val == 0:
            return None
        return root

        