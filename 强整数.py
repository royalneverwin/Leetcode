class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        res = []
        if x == 1 and y == 1:
            if bound >= 2:
                return [2]
            else:
                return []
        elif x == 1 or y == 1:
            if y == 1:
                y = x
            cur = 1
            if cur+1 <= bound:
                res.append(cur+1)
            else:
                return res
            for i in range(1, 21): # 2**20 > 1e6
                cur *= y
                if cur+1 <= bound:
                    res.append(cur+1)
                else:
                    return res
        else:
            for i in range(21):
                for j in range(21):
                    cur = x**i + y**j
                    if cur <= bound:
                        res.append(cur)
                    else:
                        break

            return list(set(res))

