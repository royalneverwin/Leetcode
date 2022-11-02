class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [[1]]
        idx = 2
        while idx <= rowIndex+1:
            if idx == 2:
                res.append([1,1])
            else:
                new = [1]
                for i in range(idx-2):
                    new.append(res[-1][i]+res[-1][i+1])
                new.append(1)
                res.append(new)
            idx += 1

        return res[-1]
