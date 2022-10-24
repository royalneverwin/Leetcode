class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        cur_min, cur_max, cur_len, flag = 0, -1, 0, False
        res = 0
        for num in arr:
            cur_max = max(cur_max, num)
            cur_len += 1
            if num == cur_min:
                flag = True
                if cur_len == cur_max-cur_min+1:
                    res += 1
                    cur_min, cur_max, cur_len, flag = cur_max+1, -1, 0, False
            else:
                if flag:
                    if cur_len == cur_max-cur_min+1:
                        res += 1
                        cur_min, cur_max, cur_len, flag = cur_max+1, -1, 0, False

        return res



