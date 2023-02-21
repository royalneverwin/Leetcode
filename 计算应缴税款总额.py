class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        res = 0
        n = len(brackets)
        for i in range(n):
            if income <= brackets[i][0]:
                if i == 0:
                    res += income * brackets[i][1] / 100
                else:
                    res += (income - brackets[i-1][0]) * brackets[i][1] / 100
                break
            else:
                if i == 0:
                    res += brackets[i][0] * brackets[i][1] / 100
                else:
                    res += (brackets[i][0] - brackets[i-1][0]) * brackets[i][1] / 100

        return res

