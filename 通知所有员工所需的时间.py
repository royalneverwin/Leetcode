class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        edge = defaultdict(list)
        l = len(manager)
        for i in range(l):
            if manager[i] != -1:
                edge[manager[i]].append(i)

        qu = deque()
        qu.append((headID, 0))
        res = 0
        while qu:
            cur_id, cur_time = qu.popleft()
            res = max(res, cur_time)
            for i in edge[cur_id]:
                qu.append((i, cur_time+informTime[cur_id]))

        return res
