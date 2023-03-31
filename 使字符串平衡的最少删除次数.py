class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        presum_a = [0 for i in range(n)] # i自后的a
        presum_b = [0 for i in range(n)] # i之前的b

        for i in range(1, n):
            if s[i-1] == 'b':
                presum_b[i] = presum_b[i-1] + 1
            else:
                presum_b[i] = presum_b[i-1]


        for i in range(n-2, -1, -1):
            if s[i+1] == 'a':
                presum_a[i] = presum_a[i+1] + 1
            else:
                presum_a[i] = presum_a[i+1]

        res = 1000000
        for i in range(n):
            res = min(res, presum_a[i]+presum_b[i])

        return res