class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        # 只要看%60的余数即可
        cnt = [0]*60
        for i in time:
            cnt[i%60] += 1

        res = 0
        for i in range(1,30):
            res += cnt[i]*cnt[60-i]

        if cnt[0] > 1:
            res += cnt[0]*(cnt[0]-1)//2
        if cnt[30] > 1:
            res += cnt[30]*(cnt[30]-1)//2

        return res