class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if i != j and i != n-1-j:
                    if grid[i][j] != 0:
                        return False

                else:
                    if grid[i][j] == 0:
                        return False

        return True