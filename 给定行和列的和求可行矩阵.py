class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        res = [[0 for j in range(n)] for i in range(m)]
        # 构造方法：对每个令res[i][j] = min(rowSum[i], colSum[j])即可
        for i in range(m):
            for j in range(n):
                res[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= res[i][j]
                colSum[j] -= res[i][j]

        return res

