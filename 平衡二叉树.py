# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def DepthAndBalanced(self, root: Optional[TreeNode]) -> int: # if balanced, return depth, else return -1
        if root:
            left = self.DepthAndBalanced(root.left)
            right = self.DepthAndBalanced(root.right)
            if left==-1 or right==-1:
                return -1
            elif abs(left-right) > 1:
                return -1
            else:
                return max(left, right)+1

        else:
            return 0
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return True if self.DepthAndBalanced(root)!=-1 else False
