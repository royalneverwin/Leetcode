class Solution:
    def maxIncreasingCells(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])

        unit_list = []
        for i in range(m):
            for j in range(n):
                unit_list.append([mat[i][j], i, j]) # val, row, col
        
        unit_list.sort(key=lambda x: x[0], reverse=True)
        
        res = 0

        max_row = [0 for i in range(m)]
        max_col = [0 for j in range(n)]

        cur_val = None
        tmp_max_row = defaultdict(int)
        tmp_max_col = defaultdict(int)
        for num, x, y in unit_list:
            if num != cur_val: # 新的数字
                # 更新max_row和max_col
                for key, val in tmp_max_row.items():
                    max_row[key] = val
                tmp_max_row = defaultdict(int)
                for key, val in tmp_max_col.items():
                    max_col[key] = val
                tmp_max_col = defaultdict(int)
                # 更新cur_val
                cur_val = num

            cur_num = 1 + max(max_row[x], max_col[y])
            if cur_num > max_row[x]:
                tmp_max_row[x] = max(tmp_max_row[x], cur_num)
            if cur_num > max_col[y]:
                tmp_max_col[y] = max(tmp_max_col[y], cur_num)

            res = max(res, cur_num)
        
        return res
