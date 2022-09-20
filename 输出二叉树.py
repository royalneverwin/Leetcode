# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        # find height
        queue = [(root, 0)]
        height = 0
        while queue:
            tmp = queue.pop(0)
            height = max(height, tmp[1])
            if tmp[0].left:
                queue.append((tmp[0].left, tmp[1]+1))
            if tmp[0].right:
                queue.append((tmp[0].right, tmp[1]+1))
        res = [['' for i in range(2**(height+1)-1)] for j in range(height+1)]
        def fill_res(root, r, c):
            res[r][c] = str(root.val)
            if root.left:
                fill_res(root.left, r+1, c-2**(height-r-1))
            if root.right:
                fill_res(root.right, r+1, c+2**(height-r-1))

        fill_res(root, 0, (2**(height+1)-2) // 2)
        return res