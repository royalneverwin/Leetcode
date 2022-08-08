"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        qu = []
        qu.append([root, 0])
        prev = None
        prevLevel = -1
        while len(qu):
            tmp = qu.pop(0)
            if prev:

                if prevLevel == tmp[1]:
                    prev.next = tmp[0]
                else:
                    prevLevel = tmp[1]
            else:
                prevLevel = tmp[1]
            prev = tmp[0]
            if tmp[0].left:
                qu.append([tmp[0].left, tmp[1]+1])
            if tmp[0].right:
                qu.append([tmp[0].right, tmp[1]+1])

        return root

