class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        prev = 1e6
        idx = -1
        n = len(arr)
        for i in range(n-1, -1, -1):
            if arr[i] <= prev:
                prev = arr[i]
                i -= 1
            else:
                idx = i
                break

        if idx == -1:
            return arr

        for i in range(n-1, idx, -1):
            if arr[i] < arr[idx]: # 一定有
                while arr[i-1] == arr[i]:
                    i -= 1
                tmp = arr[i]
                arr[i] = arr[idx]
                arr[idx] = tmp
                return arr
        