class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        max_cnt = [0] * n
        for j in range(n):
            for i in range(m):
                max_cnt[j] = max(max_cnt[j], matrix[i][j])
        
        ans = [[0]*n for i in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] != -1:
                    ans[i][j] = matrix[i][j]
                else:
                    ans[i][j] = max_cnt[j]

        return ans
