class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        if len(start) != len(end):
            return False

        # 只要start和end中L和R的相对位置相同（删去X）, 则就可以从start转化为end
        idx1, idx2 = 0, 0
        while idx1 < len(start) and idx2 < len(end):
            if start[idx1] == 'X':
                idx1 += 1
            elif end[idx2] == 'X':
                idx2 += 1
            elif start[idx1] != 'X' and end[idx2] != 'X':
                if start[idx1] != end[idx2]:
                    return False
                elif start[idx1] == 'L': # L只能左移
                    if idx1 < idx2:
                        return False
                    else:
                        idx1 += 1
                        idx2 += 1
                elif start[idx1] == 'R': # R只能右移
                    if idx1 > idx2:
                        return False
                    else:
                        idx1 += 1
                        idx2 += 1

        while idx1 < len(start):
            if start[idx1] != 'X':
                return False
            idx1 += 1

        while idx2 < len(end):
            if end[idx2] != 'X':
                return False
            idx2 += 1

        return True




