class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        flag_row, flag_col = 0, 0
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if not matrix[row][col]:
                    flag_row |= (1 << row)
                    flag_col |= (1 << col)

        for row in range(len(matrix)):
            if flag_row & (1 << row):
                for col in range(len(matrix[0])):
                    matrix[row][col] = 0

        for col in range(len(matrix[0])):
            if flag_col & (1 << col):
                for row in range(len(matrix)):
                    matrix[row][col] = 0

        