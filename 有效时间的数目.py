class Solution:
    def countTime(self, time: str) -> int:
        res = 1
        if time[0] == '?' and time[1] == '?':
            res *= 24
        elif time[0] == '?' and time[1] in ['0', '1', '2', '3']:
            res *= 3
        elif time[0] == '?':
            res *= 2
        elif time[0] == '2' and time[1] == '?':
            res *= 4
        elif time[0] in ['0', '1'] and time[1] == '?':
            res *= 10


        if time[3] == '?':
            res *= 6


        if time[4] == '?':
            res *= 10


        return res