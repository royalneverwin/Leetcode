# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if root == None:
            return root

        if root.val > high:
            return self.trimBST(root.left, low, high)

        elif root.val == high:
            root.right = None
            root.left = self.trimBST(root.left, low, high)
            return root

        elif root.val > low:
            root.left = self.trimBST(root.left, low, high)
            root.right = self.trimBST(root.right, low, high)
            return root

        elif root.val == low:
            root.left = None
            root.right = self.trimBST(root.right, low, high)
            return root

        else:
            return self.trimBST(root.right, low, high)
