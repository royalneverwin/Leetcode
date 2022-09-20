# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue = [(root, 0, 0)]
        res = 0
        cur_layer = 0
        min_idx, max_idx = 0, 0
        while queue:
            tmp = queue.pop(0)
            if tmp[2] == cur_layer:
                max_idx = tmp[1]
            else:
                res = max(res, max_idx - min_idx + 1)
                cur_layer = tmp[2]
                min_idx = tmp[1]
                max_idx = tmp[1]

            if tmp[0].left:
                queue.append((tmp[0].left, 2*tmp[1]+1, tmp[2]+1))
            if tmp[0].right:
                queue.append((tmp[0].right, 2*tmp[1]+2, tmp[2]+1))
        res = max(res, max_idx - min_idx + 1)
        return res