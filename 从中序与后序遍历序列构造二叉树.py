# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if len(inorder) == 0:
            return None

        elif len(inorder) == 1:
            return TreeNode(inorder[0])

        value = postorder[-1]
        Inleft = []
        Inright = []
        Postleft = postorder[0:len(postorder)-1]
        Postright = []

        for i in range(0, len(inorder)):
            if inorder[i] == value:
                Inleft = inorder[0:i]
                Inright = inorder[i+1:]
                break

        if len(Inright) > 0:
            Postleft = postorder[0:len(Inleft)]
            Postright = postorder[len(Inleft):len(postorder)-1]

        return TreeNode(value, self.buildTree(Inleft, Postleft), self.buildTree(Inright, Postright))