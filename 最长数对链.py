class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # 贪心
        pairs.sort(key=lambda x: x[1])
        cnt = 0
        prev = None
        for i in pairs:
            if prev == None or i[0] > prev:
                cnt += 1
                prev = i[1]
        return cnt