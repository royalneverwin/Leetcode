class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        cur = 0 # 0, 1, 2, 3表示北东南西
        cnt1, cnt2 = 0, 0
        for c in instructions:
            if c == 'L':
                cur -= 1
            elif c == 'R':
                cur += 1
            else:
                if cur % 4 == 0:
                    cnt2 += 1
                elif cur % 4 == 1:
                    cnt1 += 1
                elif cur % 4 == 2:
                    cnt2 -= 1
                else:
                    cnt1 -= 1

        if cur % 4 == 1 or cur % 4 == 3:
            return True
        elif cur % 4 == 0 and cnt1 == 0 and cnt2 == 0:
            return True
        elif cur % 4 == 2 and (cnt1 == 0 or cnt2 == 0 or abs(cnt1) == abs(cnt2)):
            return True
        else:
            return False



