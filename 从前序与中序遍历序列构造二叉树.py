# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None

        elif len(preorder) == 1:
            return TreeNode(preorder[0])

        value = preorder[0]
        Inleft = []
        Inright = []
        Preleft = preorder[1:]
        Preright = []

        for i in range(0, len(inorder)):
            if inorder[i] == value:
                Inleft = inorder[0:i]
                Inright = inorder[i+1:]
                break

        if len(Inright) > 0:
            Preleft = preorder[1:len(Inleft)+1]
            Preright = preorder[len(Inleft)+1:]


        return TreeNode(value, self.buildTree(Preleft, Inleft), self.buildTree(Preright, Inright))