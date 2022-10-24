class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        idx1, idx2 = 0, 1
        my_dic = [[fruits[0], 1], [None, 0]]
        res = 1
        cur = 1
        while idx2 < len(fruits):
            if fruits[idx2] == my_dic[0][0]:
                my_dic[0][1] += 1
                cur += 1
            elif my_dic[1][0] == None:
                my_dic[1][0] = fruits[idx2]
                my_dic[1][1] = 1
                cur += 1
            elif fruits[idx2] == my_dic[1][0]:
                my_dic[1][1] += 1
                cur += 1
            else:
                while True:
                    if fruits[idx1] == my_dic[0][0]:
                        my_dic[0][1] -= 1
                        idx1 += 1
                        cur -= 1
                        if my_dic[0][1] == 0:
                            my_dic[0][0] = fruits[idx2]
                            my_dic[0][1] = 1
                            cur += 1
                            break
                    else:
                        my_dic[1][1] -= 1
                        idx1 += 1
                        cur -= 1
                        if my_dic[1][1] == 0:
                            my_dic[1][0] = fruits[idx2]
                            my_dic[1][1] = 1
                            cur += 1
                            break

            res = max(cur, res)
            idx2 += 1

        return res




