# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        path = dict()
        def dfs1(root, path_val):
            nonlocal path
            if (root in path and path[root] < path_val+root.val) or root not in path:
                path[root] = path_val+root.val
                if root.left:
                    dfs1(root.left, path[root])

                if root.right:
                    dfs1(root.right, path[root])

        def dfs2(root):
            if root.left and root.right:
                flag1, flag2 = dfs2(root.left), dfs2(root.right)
                if flag1 == False and flag2 == False:
                    root.left = None
                    root.right = None
                    return False
                elif flag1 == False:
                    root.left = None
                    return True
                elif flag2 == False:
                    root.right = None
                    return True
                else:
                    return True
            elif root.left:
                flag = dfs2(root.left)
                if flag == False:
                    root.left = None
                return flag
            elif root.right:
                flag = dfs2(root.right)
                if flag == False:
                    root.right = None
                return flag
            else: # 叶子节点
                if path[root] < limit:
                    return False
                else:
                    return True


        dfs1(root, 0) # 先记录每个node从根节点到他的最大路径值
        flag = dfs2(root) # 在寻找节点是否不存在到叶子结点大于0的路径
        if flag == False:
            return None
        return root




