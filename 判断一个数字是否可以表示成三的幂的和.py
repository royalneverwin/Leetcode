class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        flag = True
        while n > 0:
            if n % 3 == 0:
                flag = True
                n //= 3
            else:
                if flag:
                    n -= 1
                    flag = False
                else:
                    return False

        return True