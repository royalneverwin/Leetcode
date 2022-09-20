class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        row_list = [-1 for i in range(len(mat))] # 存放每一行若只有唯一的1 则1的列数 -1则为没有
        for i in range(len(mat)): # 对每一行
            flag = False
            for j in range(len(mat[0])):
                if mat[i][j] == 1 and flag == False:
                    flag = True
                    row_list[i] = j

                elif mat[i][j] == 1 and flag == True:
                    row_list[i] = -1
                    break

        col_list = [-1 for j in range(len(mat[0]))] #存放每一列若只有唯一的1 则1的行数 -1则为没有

        for j in range(len(mat[0])):
            flag = False
            for i in range(len(mat)):
                if mat[i][j] == 1 and flag == False:
                    flag = True
                    col_list[j] = i
                elif mat[i][j] == 1 and flag == True:
                    col_list[j] = -1
                    break

        res = 0
        for i in row_list:
            if i != -1 and col_list[i] != -1:
                res += 1
        return res