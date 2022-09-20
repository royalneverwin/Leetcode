# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        ret = 0
        cur_layer = 0
        queue = [(root, 0)]

        while queue != []:
            tmp = queue[0]
            queue.pop(0)
            if tmp[1] == cur_layer:
                ret += tmp[0].val
            else:
                cur_layer = tmp[1]
                ret = tmp[0].val

            if tmp[0].left:
                queue.append((tmp[0].left, tmp[1]+1))
            if tmp[0].right:
                queue.append((tmp[0].right, tmp[1]+1))

        return ret
