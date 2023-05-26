# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        res = None
        def getAttr(root): # return sum, minLeft, maxRight, isBST
            # isBST的作用是判断左子树和右子树是不是二叉搜索树
            nonlocal res
            if root.left:
                left_sum, left_min_left, left_max_right, left_BST = getAttr(root.left)
            else:
                left_sum, left_min_left, left_max_right, left_BST = 0, root.val, root.val-1, True
            if root.right:
                right_sum, right_min_left, right_max_right, right_BST = getAttr(root.right)
            else:
                right_sum, right_min_left, right_max_right, right_BST = 0, root.val+1, root.val, True

            if left_BST and right_BST:
                if left_max_right < root.val and right_min_left > root.val: # 是BST
                    if res == None:
                        res = left_sum+right_sum+root.val
                    else:
                        res = max(res, left_sum+right_sum+root.val)
                    return left_sum+right_sum+root.val, left_min_left, right_max_right, True

                else:
                    return left_sum+right_sum+root.val, left_min_left, right_max_right, False
            else: # 不是BST
                return left_sum+right_sum+root.val, left_min_left, right_max_right, False

        getAttr(root)
        return max(res, 0) # 空的树也算二叉搜索树


