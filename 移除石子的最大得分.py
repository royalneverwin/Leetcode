class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        if a < b:
            if c < a:
                x1, x2, x3 = c, a, b
            elif a < c and c < b:
                x1, x2, x3 = a, c, b
            else:
                x1, x2, x3 = a, b, c
        else:
            if c < b:
                x1, x2, x3 = c, b, a
            elif b < c and c < a:
                x1, x2, x3 = b, c, a
            else:
                x1, x2, x3 = b, a, c

        if x3-x2 >= x1:
            return x2+x1
        elif (x1-x3+x2) % 2 == 0:
            return x2-x1 + 2*(x3-x2) + (x1-x3+x2)//2*3
        else:
            return x2-x1 + 2*(x3-x2) + (x1-x3+x2-1)//2*3+1


        # x1, x1, x3-x2+x1    x2-x1
        # 若x3-x2 > x1: -> 2x1
        # 若x3-x2 < x1: -> x1-x3+x2, x1-x3+x2, x1-x3+x2 2(x3-x2)
        # if x1-x3+x2 % 2 == 0: (x1-x3+x2)//2 * 3; else:(x1-x3+x2-1)//2 * 3+1