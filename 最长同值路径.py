# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(root): # 计算一定包括root节点的最长路径长度 同时返回最长的一边 同时更新ans 这样dfs(root)的时候我们可以算出包括且不包括root时的最长路径
            if root == None:
                return 0
            left, right = dfs(root.left), dfs(root.right)
            if root.left and root.left.val == root.val:
                left += 1
            else:
                left = 0

            if root.right and root.right.val == root.val:
                right += 1
            else:
                right = 0
            nonlocal ans
            ans = max(ans, left + right)
            return max(left, right)
        dfs(root)
        return ans

# 很妙！函数中更新的ans和返回的不一样 既计算了经过root的最长路径也计算了不经过root的 妙不可言