"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def dfs(self, ans, root: 'Node'):
        if root is not None:
            for i in root.children:
                Solution.dfs(self, ans, i)
            ans.append(root.val)
    def postorder(self, root: 'Node') -> List[int]:
        ans = list()
        Solution.dfs(self, ans, root)
        return ans
