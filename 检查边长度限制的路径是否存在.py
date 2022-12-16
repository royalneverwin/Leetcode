class Solution:

    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        # 用并查集 将长度小于limit的边都加入然后能连通的边合一起
        # 重排queries 将limit递增 这样每次忘并查集添加新的边即可
        father = [i for i in range(n)]
        len_e, len_q = len(edgeList), len(queries)
        res = [False for i in range(len_q)]
        edge_idx = 0

        def parent(x):
            nonlocal father
            if father[x] == x:
                return father[x]
            else:
                father[x] = parent(father[x])
                return father[x]

        def merge(x, y):
            nonlocal father
            fx = parent(x)
            fy = parent(y)
            father[fy] = fx

        edgeList.sort(key=lambda x: x[2])
        queries = list(enumerate(queries))
        queries.sort(key=lambda x: x[1][2])

        for idx, query in queries:
            while edge_idx < len_e and edgeList[edge_idx][2] < query[2]:
                merge(edgeList[edge_idx][0], edgeList[edge_idx][1])
                edge_idx += 1
            if parent(query[0]) == parent(query[1]):
                res[idx] = True

        return res


