class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        l = len(logs)
        res, max_t, prev = 1e10, 0, 0
        for i in range(l):
            if logs[i][1]-prev > max_t:
                res = logs[i][0]
                max_t = logs[i][1]-prev
            elif logs[i][1]-prev == max_t:
                res = min(res, logs[i][0])
            prev = logs[i][1]

        return res
