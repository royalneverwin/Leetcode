class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # 贪心
        intervals = []
        for i in range(n+1):
            interval = [i-ranges[i], i+ranges[i]]
            intervals.append(interval)

        intervals.sort(key=lambda x: x[1], reverse=True)
        left = 0
        res = 0
        index = n+1
        while left < n:
            flag = False
            for i in range(index):
                if intervals[i][0] <= left:
                    res += 1
                    left = intervals[i][1]
                    index = i
                    flag = True
                    break

            if not flag:
                return -1


        return res