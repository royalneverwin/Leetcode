class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        # x ^ k == 00000 or 11111
        # x ^ k ^ k == 00000 ^ k or 11111 ^ k
        # x ^ k ^ k = x
        # x == 00000 ^ k or 11111 ^ k
        # x == k or ~k
        cnt = defaultdict(int)
        for row in matrix:
            x = ''
            x_inverse = ''
            for i in row:
                x += str(i)
                x_inverse += str(i ^ 1)

            cnt[x] += 1
            cnt[x_inverse] += 1

        res = [cnt[key] for key in cnt.keys()]
        return max(res)
