# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        res = []
        def AddTree(root, flag):
            if root.val in to_delete:
                if root.left:
                    AddTree(root.left, True)
                if root.right:
                    AddTree(root.right, True)
                return None
            else:
                if flag:
                    res.append(root)
                if root.left:
                    root.left = AddTree(root.left, False)
                if root.right:
                    root.right = AddTree(root.right, False)
                return root

        AddTree(root, True)
        return res