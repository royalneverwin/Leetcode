class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x:  x[1], reverse=True)
        res = 0
        for boxType in boxTypes:
            if truckSize >= boxType[0]:
                res += boxType[0] * boxType[1]
                truckSize -= boxType[0]
            else:
                res += truckSize * boxType[1]
                break
        return res