class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        n = len(obstacles)-1 # 共3n+3个点, 每3个为一份 n//3表示第几份 n%3表示一份中第几个
        flag = [1000000000 for i in range(3*n+3)]
        qu = [] # （x, y）x表示第x个点 y表示侧跳y次
        qu.append((1, 0))
        while True:
            tmp = qu.pop(0)
            point, road, step = tmp[0] // 3, tmp[0] % 3, tmp[1]

            if point == n-1:
                return step

            if road == 0:
                if obstacles[point] != 2:
                    nxt = tmp[0]+1
                    if flag[nxt] > step+1:
                        qu.append((nxt, step+1))
                        flag[nxt] = step+1
                if obstacles[point] != 3:
                    nxt = tmp[0]+2
                    if flag[nxt] > step+1:
                        qu.append((nxt, step+1))
                        flag[nxt] = step+1
            if road == 1:
                if obstacles[point] != 1:
                    nxt = tmp[0]-1
                    if flag[nxt] > step+1:
                        qu.append((nxt, step+1))
                        flag[nxt] = step+1
                if obstacles[point] != 3:
                    nxt = tmp[0]+1
                    if flag[nxt] > step+1:
                        qu.append((nxt, step+1))
                        flag[nxt] = step+1
            if road == 2:
                if obstacles[point] != 1:
                    nxt = tmp[0]-2
                    if flag[nxt] > step+1:
                        qu.append((nxt, step+1))
                        flag[nxt] = step+1
                if obstacles[point] != 2:
                    nxt = tmp[0]-1
                    if flag[nxt] > step+1:
                        qu.append((nxt, step+1))
                        flag[nxt] = step+1


            if obstacles[point+1] != road+1:
                nxt = tmp[0]+3
                if flag[nxt] > step:
                    qu.append((nxt, step))
                    flag[nxt] = step








