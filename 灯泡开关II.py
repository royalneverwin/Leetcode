class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        # 统一操作做两次就等于没做
        # 所以等于列举操作做了偶数次还是寄数次
        # 若presses是偶数 则可能都做了奇数次 两个做了奇数次和都做了偶数次
        # 若presses是奇数 则可能一个做了奇数次或3个做了奇数次
        if presses % 2: #奇
            if presses == 1: # 只可能1个做了奇数次
                if n == 1:
                    return 2
                elif n == 2:
                    return 3
                else:
                    return 4
            else:
                if n == 1:
                    return 2
                elif n == 2:
                    return 4
                else:
                    return 8
        else: # 偶
            if presses == 0: # 只可能都没做
                return 1
            elif presses == 2: # 只可能都偶数次或两个奇数次
                if n == 1:
                    return 2
                elif n == 2:
                    return 4
                else:
                    return 7
            else:
                if n == 1:
                    return 2
                elif n == 2:
                    return 4
                else:
                    return 8

