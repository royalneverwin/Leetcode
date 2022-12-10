class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        edge_list = [{} for i in range(n)]
        edge_flag = {}
        for edge in edges:
            edge_list[edge[0]][edge[1]] = edge[2]
            edge_list[edge[1]][edge[0]] = edge[2]
            edge_flag[(edge[0], edge[1])] = 0
            edge_flag[(edge[1], edge[0])] = 0
        visited = set()
        nodes_cnt = 0
        pq = [[0, 0]] # 第一个是距离 第二个是节点
        while pq and pq[0][0] <= maxMoves: # 狄杰斯特拉算法 这里我们只要维护一个队列 因为重点是遍历到的节点而不是距离
            dis, u = heapq.heappop(pq)
            if u in visited: #  之前已经遍历过了 这里就不需要了
                continue
            visited.add(u)
            nodes_cnt += 1

            for v, l in edge_list[u].items():
                edge_flag[(u, v)] = min(maxMoves-dis, l)
                heapq.heappush(pq, [dis+l+1, v])

        res = nodes_cnt
        for u, v, dis in edges:
            res += min(dis, edge_flag[(u, v)]+edge_flag[(v, u)])

        return res







