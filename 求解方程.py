class Solution:
    def solveEquation(self, equation: str) -> str:
        idx = 0
        while equation[idx] != '=':
            idx += 1

        left_equ = equation[0:idx]
        right_equ = equation[idx+1:]

        idx1, idx2 = 0, 0
        x_cnt_left, const_left, is_add = 0, 0, True
        if left_equ[0] == '-':
            is_add = False
            idx1 = idx2 = 1
        while idx2 < len(left_equ):
            while idx2 < len(left_equ) and left_equ[idx2] != '+' and left_equ[idx2] != '-':
                idx2 += 1
            if is_add:
                if left_equ[idx2-1] == 'x':
                    if left_equ[idx1] == 'x':
                        x_cnt_left += 1
                    else:
                        x_cnt_left += int(left_equ[idx1:idx2-1])
                else:
                    const_left += int(left_equ[idx1:idx2])
            else:
                if left_equ[idx2-1] == 'x':
                    if left_equ[idx1] == 'x':
                        x_cnt_left -= 1
                    else:
                        x_cnt_left -= int(left_equ[idx1:idx2-1])
                else:
                    const_left -= int(left_equ[idx1:idx2])
            if idx2 < len(left_equ) and left_equ[idx2] == '+':
                is_add = True
            elif idx2 < len(left_equ):
                is_add = False
            idx1 = idx2+1
            idx2 = idx1

        idx1, idx2 = 0, 0
        x_cnt_right, const_right, is_add = 0, 0, True
        if right_equ[0] == '-':
            is_add = False
            idx1 = idx2 = 1
        while idx2 < len(right_equ):
            while idx2 < len(right_equ) and right_equ[idx2] != '+' and right_equ[idx2] != '-':
                idx2 += 1
            if is_add:
                if right_equ[idx2-1] == 'x':
                    if right_equ[idx1] == 'x':
                        x_cnt_right += 1
                    else:
                        x_cnt_right += int(right_equ[idx1:idx2-1])
                else:
                    const_right += int(right_equ[idx1:idx2])
            else:
                if right_equ[idx2-1] == 'x':
                    if right_equ[idx1] == 'x':
                        x_cnt_right -= 1
                    else:
                        x_cnt_right -= int(right_equ[idx1:idx2-1])
                else:
                    const_right -= int(right_equ[idx1:idx2])
            if idx2 < len(right_equ) and right_equ[idx2] == '+':
                is_add = True
            elif idx2 < len(right_equ):
                is_add = False
            idx1 = idx2+1
            idx2 = idx1

        if x_cnt_left == x_cnt_right and const_left == const_right:
            return 'Infinite solutions'

        if x_cnt_left == x_cnt_right and const_left != const_right:
            return 'No solution'
        return f'x={(const_right-const_left) // (x_cnt_left-x_cnt_right)}'  