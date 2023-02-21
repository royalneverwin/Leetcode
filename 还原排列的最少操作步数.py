class Solution:
    def reinitializePermutation(self, n: int) -> int:
        # 变一下之后所有偶数部分存前半段 奇数部分存后半段
        res = 0
        perm = [i for i in range(n)]
        while True:
            arr = [0 for i in range(n)]
            res += 1
            for i in range(n):
                if i % 2 == 0:
                    arr[i] = perm[i // 2]
                else:
                    arr[i] = perm[n // 2 + (i-1) // 2]

            flag = True
            for i in range(n):
                if arr[i] != i:
                    flag = False
                    perm = arr
                    break
            if flag:
                return res

