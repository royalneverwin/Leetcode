class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        # 首先要知道怎么算一棵树的直径 最大距离
        # 因为n = 16 所以可以遍历所有可能 先判断算不算 子树 如果算找到树的直径即可
        adj_node = {}
        res = [0 for i in range(n-1)]
        for edge in edges:
            if edge[0] in adj_node:
                adj_node[edge[0]].append(edge[1])
            else:
                adj_node[edge[0]] = [edge[1]]

            if edge[1] in adj_node:
                adj_node[edge[1]].append(edge[0])
            else:
                adj_node[edge[1]] = [edge[0]]

        for mask in range(2**n):
            # 排除小于2个城市的
            city = set()
            begin_city = -1
            for i in range(n):
                if mask & (1 << i):
                    if begin_city == -1:
                        begin_city = i+1
                    city.add(i+1)
            if len(city) < 2:
                continue

            # 判断是不是子树
            flag = [1 for i in range(n)]
            for c in city:
                flag[c-1] = 0

            qu = [begin_city]

            while len(qu):
                c = qu[0]
                qu.pop(0)
                flag[c-1] = 1
                for adj in adj_node[c]:
                    if flag[adj-1] == 0:
                        qu.append(adj)

            if sum(flag) != n:
                continue

            # 寻找子树的直径
            # 两次DFS即可
            # 第一次DFS
            flag = [1 for i in range(n)]
            for c in city:
                flag[c-1] = 0
            qu = [(begin_city, 0)]
            edge_x = begin_city
            max_dis = 0

            while len(qu):
                c, dis = qu[0]
                qu.pop(0)
                if dis > max_dis:
                    edge_x = c
                    max_dis = dis
                flag[c-1] = 1
                for adj in adj_node[c]:
                    if flag[adj-1] == 0:
                        qu.append((adj, dis+1))

            # 第二次DFS
            flag = [1 for i in range(n)]
            for c in city:
                flag[c-1] = 0
            qu = [(edge_x, 0)]
            max_dis = 0

            while len(qu):
                c, dis = qu[0]
                qu.pop(0)
                if dis > max_dis:
                    max_dis = dis
                flag[c-1] = 1
                for adj in adj_node[c]:
                    if flag[adj-1] == 0:
                        qu.append((adj, dis+1))

            res[max_dis-1] += 1

        return res

        