class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        res = 100000
        cur_res = 0
        idx1, idx2 = 0, k-1
        n = len(blocks)
        for i in range(idx1, idx2+1):
            if blocks[i]== 'W':
                cur_res += 1

        res = min(res, cur_res)
        while idx2 != n-1:
            if blocks[idx1] == 'W':
                cur_res -= 1
            idx2 += 1
            idx1 += 1
            if blocks[idx2] == 'W':
                cur_res += 1
            res = min(res, cur_res)

        return res
