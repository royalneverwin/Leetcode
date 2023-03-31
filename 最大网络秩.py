class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        my_hash = set()
        cnt = [0 for i in range(n)]
        for road in roads:
            cnt[road[0]] += 1
            cnt[road[1]] += 1
            my_hash.add((road[0], road[1]))
            my_hash.add((road[1], road[0]))

        res = 0
        for i in range(n-1):
            for j in range(i+1, n):
                cur = cnt[i]+cnt[j]
                if (i, j) in my_hash:
                    cur -= 1
                res = max(res, cur)

        return res
