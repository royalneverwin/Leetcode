class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        parent = [i for i in range(n)]
        def father(a):
            nonlocal parent
            if parent[a] == a:
                return a
            else:
                parent[a] = father(parent[a])
                return parent[a]

        def merge(a, b):
            nonlocal parent
            fa = father(a)
            fb = father(b)
            parent[fa] = fb

        for edge in edges:
            merge(edge[0], edge[1])

        if father(source) == father(destination):
            return True
        else:
            return False
