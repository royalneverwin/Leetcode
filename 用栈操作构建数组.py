class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        idx = 0
        cur = 1
        res = []
        while idx < len(target):
            if target[idx] == cur:
                res.append('Push')
                cur += 1
                idx += 1
            else:
                res.append('Push')
                res.append('Pop')
                cur += 1

        return res

