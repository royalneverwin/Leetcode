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
    def connect(self, root: 'Node') -> 'Node':
        prev = None
        cur_layer = 0
        if not root:
            return root
        queue = [(root, 0)]
        while queue:
            tmp = queue.pop(0)
            if tmp[1] == cur_layer:
                if prev:
                    prev.next = tmp[0]
            else:
                cur_layer = tmp[1]

            prev = tmp[0]
            if tmp[0].left:
                queue.append((tmp[0].left, tmp[1]+1))
            if tmp[0].right:
                queue.append((tmp[0].right, tmp[1]+1))
        return root