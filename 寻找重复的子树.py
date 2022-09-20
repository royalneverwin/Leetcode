# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        seq = dict()
        ans = set()
        def dfs(root): # 序列化
            nonlocal seq
            nonlocal ans
            if root == None:
                return ''

            res = ''.join((str(root.val), '(', dfs(root.left), ')(', dfs(root.right), ')'))

            if (node := seq.get(res, None)):
                ans.add(node)
            else:
                seq[res] = root

            return res

        dfs(root)
        return list(ans)


            