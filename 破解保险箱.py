class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        # 重点是转化成有向图求欧拉回路
        flag = set()
        bound = int(pow(10, n-1))
        res = ''
        def dfs(cur):
            nonlocal k
            nonlocal bound
            nonlocal flag
            nonlocal res
            for i in range(k):
                nxt = (cur * 10 + i)
                if nxt not in flag: # 这条边没遍历过
                    flag.add(nxt)
                    dfs(nxt % bound)
                    res += str(i)
        dfs(0)
        res += '0' * (n-1)
        return res