class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        target = (query_row, query_glass)
        in_idx = [[0.0 for i in range(query_row+1)] for j in range(query_row+1)]
        cur_idx = [[0.0 for i in range(query_row+1)] for j in range(query_row+1)]
        out_idx = [[0.0 for i in range(query_row+1)] for j in range(query_row+1)]
        in_idx[0][0] = poured
        if in_idx[0][0] >= 1:
            cur_idx[0][0] = 1
            out_idx[0][0] = (in_idx[0][0]-1) / 2
        else:
            cur_idx[0][0] = in_idx[0][0]
            out_idx[0][0] = 0
        for i in range(1, query_row+1):
            for j in range(i+1):
                if j == 0:
                    in_idx[i][j] = out_idx[i-1][j]
                elif j == i:
                    in_idx[i][j] = out_idx[i-1][j-1]
                else:
                    in_idx[i][j] = out_idx[i-1][j-1] + out_idx[i-1][j]
                if in_idx[i][j] >= 1:
                    cur_idx[i][j] = 1
                    out_idx[i][j] = (in_idx[i][j]-1) / 2
                else:
                    cur_idx[i][j] = in_idx[i][j]
                    out_idx[i][j] = 0

        return cur_idx[query_row][query_glass]






    