class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        res = 1e10
        for i in range(len(triangle)):
            for j in range(len(triangle[i])):
                if i == len(triangle)-1:
                    res = min(res, triangle[i][j])
                elif j == 0:
                    triangle[i+1][j] = triangle[i][j]+triangle[i+1][j]
                    if i != 0:
                        triangle[i+1][j+1] = min(triangle[i][j]+triangle[i+1][j+1], triangle[i][j+1]+triangle[i+1][j+1])
                    else:
                        triangle[i+1][j+1] = triangle[i][j]+triangle[i+1][j+1]
                elif j < len(triangle[i])-1:
                    triangle[i+1][j+1] = min(triangle[i][j]+triangle[i+1][j+1], triangle[i][j+1]+triangle[i+1][j+1])
                elif j == len(triangle[i])-1:
                    triangle[i+1][j+1] = triangle[i][j]+triangle[i+1][j+1]
        return res
