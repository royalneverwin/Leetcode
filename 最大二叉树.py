# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        idx = nums.index(max(nums))
        return TreeNode(nums[idx], self.constructMaximumBinaryTree(nums[0:idx]), self.constructMaximumBinaryTree(nums[idx+1:]))
