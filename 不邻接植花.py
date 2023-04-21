class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        edge = {}
        for i in range(1, n+1):
            edge[i] = []
        len_p = len(paths)
        for i in range(len_p):
            edge[paths[i][0]].append(paths[i][1])
            edge[paths[i][1]].append(paths[i][0])

        flag = [0 for i in range(n+1)]

        ans = [0 for i in range(n)]

        left = [[1, 2, 3, 4] for i in range(n+1)]

        qu = deque()

        while True:
            for i in range(1, n+1):
                if flag[i] == 0:
                    qu.append(i)
                    flag[i] = 1
                    break
            if qu:
                while qu:
                    idx = qu.popleft()
                    ans[idx-1] = left[idx][0]
                    for i in edge[idx]:
                        if flag[i] == 0:
                            qu.append(i)
                            flag[i] = 1
                        if ans[i-1] == 0:
                            if left[idx][0] in left[i]:
                                drop = left[i].index(left[idx][0])
                                left[i].pop(drop)
            else:
                break

        return ans

