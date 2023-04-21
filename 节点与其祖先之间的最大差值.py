# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        qu = deque()
        qu.append((root, root.val, root.val))

        res = 0
        while qu:
            cur, min_v, max_v = qu.popleft()
            min_v = min(min_v, cur.val)
            max_v = max(max_v, cur.val)
            res = max(res, max_v-min_v)

            if cur.left:
                qu.append((cur.left, min_v, max_v))
            if cur.right:
                qu.append((cur.right, min_v, max_v))


        return res