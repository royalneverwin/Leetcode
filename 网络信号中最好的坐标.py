class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        signal = [[0 for i in range(51)] for j in range(51)]
        for i in range(51):
            for j in range(51):
                for k in range(len(towers)):
                    d = ((towers[k][0]-i)**2+(towers[k][1]-j)**2)**0.5
                    if d <= radius:
                        signal[i][j] += int(towers[k][2]/(1+d))

        res = [0, 0, 0]
        for i in range(51):
            for j in range(51):
                if signal[i][j] > res[2]:
                    res[0], res[1], res[2] = i, j, signal[i][j]

        return res[:2]