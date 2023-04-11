class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        idx1, idx2 = 0, n-1
        nxt = 10000000000000
        # 剩余数组在末尾
        while idx2 >= 0 and arr[idx2] <= nxt:
            nxt = arr[idx2]
            idx2 -= 1

        if idx2 == -1:
            return 0
        idx2 += 1 # 退到连续的开头
        res = idx2
        # 剩余数组在开头和末尾
        prev = -1
        while idx1 < idx2:
            if arr[idx1] <= arr[idx2] and arr[idx1] >= prev: # 可以留下
                prev = arr[idx1]
                idx1 += 1
            elif arr[idx1] < prev:
                break
            else: # 无法留下 临界条件
                res = min(res, idx2-idx1)
                while idx2 < n and arr[idx1] > arr[idx2]:
                    idx2 += 1
                if idx2 == n:
                    break
        res = min(res, idx2-idx1)

        # 剩余数组在开头
        prev = -1
        idx1 = 0
        while idx1 <n  and arr[idx1] >= prev:
            prev = arr[idx1]
            idx1 += 1
        idx1 -= 1 # 退到连续的末尾
        res = min(res, n-idx1-1)
        return res


