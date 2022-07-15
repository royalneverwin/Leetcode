"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def intersect(self, quadTree1: 'Node', quadTree2: 'Node') -> 'Node':
        if quadTree1.isLeaf:
            if quadTree1.val:
                return quadTree1
            else:
                return quadTree2
        elif quadTree2.isLeaf:
            if quadTree2.val:
                return quadTree2
            else:
                return quadTree1
        else:
            ret = Node()
            ret.val = True
            ret.isLeaf = False
            ret.topLeft = Solution.intersect(self, quadTree1.topLeft, quadTree2.topLeft)
            ret.topRight = Solution.intersect(self, quadTree1.topRight, quadTree2.topRight)
            ret.bottomLeft = Solution.intersect(self, quadTree1.bottomLeft, quadTree2.bottomLeft)
            ret.bottomRight = Solution.intersect(self, quadTree1.bottomRight, quadTree2.bottomRight)
            # 合并
            if ret.topLeft.isLeaf and ret.topRight.isLeaf and ret.bottomLeft.isLeaf and ret.bottomRight.isLeaf and ret.topLeft.val == ret.topRight.val and ret.topRight.val == ret.bottomRight.val and ret.bottomRight.val == ret.bottomLeft.val:
                ret.val = ret.topRight.val
                ret.isLeaf = True
                ret.topLeft = ret.topRight = ret.bottomLeft = ret.bottomRight = None
            return ret
