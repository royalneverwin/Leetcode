# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetricSub(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 == None and root2 == None:
            return True
        elif root1 == None:
            return False
        elif root2 == None:
            return False
        else:
            if root1.val != root2.val:
                return False
            return self.isSymmetricSub(root1.left, root2.right) and self.isSymmetricSub(root1.right, root2.left)
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isSymmetricSub(root.left, root.right)