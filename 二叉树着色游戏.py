# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        # 二号肯定选一号的相邻节点
        # 一号节点把二叉树分成了三部分
        # 锁定的的节点一定是最多节点的部分的入口
        def FindTree(root, x):
            if root.val == x:
                return root
            else:
                res = None
                if root.left:
                    res = FindTree(root.left, x)
                if res == None and root.right:
                    res = FindTree(root.right, x)
                return res

        x = FindTree(root, x)
        def getSubTree(root, n, x):
            res = 1
            if x.left != None:
                res += getSubTree(root, n, x.left)
            if x.right != None:
                res += getSubTree(root, n, x.right)
            return res

        if x.left == None:
            left = 0
        else:
            left = getSubTree(root, n, x.left)

        if x.right == None:
            right = 0
        else:
            right = getSubTree(root, n, x.right)
        up = n-left-right-1
        if left > (n-1) // 2 or right > (n-1) //2 or up > (n-1) // 2:
            return True
        else:
            return False


