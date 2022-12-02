class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0 for i in range(n)]
        for i in range(n):
            cur = 0
            for j in range(n):
                if j != i:
                    if boxes[j] == '1':
                        cur += abs(j-i)

            res[i] = cur
        return res