# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        def insert(father, root, val):
            if val > root.val:
                if father == None:
                    ret = TreeNode(val, root, None)
                    return ret
                else:
                    father.right = TreeNode(val, root, None)
                    return root
            else:
                if root.right == None:
                    root.right = TreeNode(val, None, None)
                else:
                    insert(root, root.right, val)
                return root

        return insert(None, root, val)