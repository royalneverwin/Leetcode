class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        red_edges = defaultdict(list)
        blue_edges = defaultdict(list)

        for edge in redEdges:
            red_edges[edge[0]].append(edge[1])
        for edge in blueEdges:
            blue_edges[edge[0]].append(edge[1])

        qu = deque()
        ans = [[-1 for i in range(n)] for j in range(2)]
        ans[0][0] = 0
        ans[1][0] = 0
        qu.append((0, 0, 0)) # prev = 0 表示前一个红色 prev = 1 表示前一个蓝色
        qu.append((0, 1, 0)) # prev = 0 表示前一个红色 prev = 1 表示前一个蓝色
        while qu:
            node, prev, l = qu.popleft()
            if prev == 1:
                for i in red_edges[node]:
                    if ans[1][i] == -1:
                        ans[1][i] = l+1
                        qu.append((i, 0, l+1))
            else:
                for i in blue_edges[node]:
                    if ans[0][i] == -1:
                        ans[0][i] = l+1
                        qu.append((i, 1, l+1))

        res = [-1 for i in range(n)]
        for i in range(n):
            res[i] = min(ans[0][i], ans[1][i]) if ans[0][i] != -1 and ans[1][i] != -1 else max(ans[0][i], ans[1][i])
        return res

