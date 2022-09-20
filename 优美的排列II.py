class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        # [1, 2, 3, 4, ..., n] k = 1最小
        # [1, n, 2, n-1, 3, n-2, ...] k = n-1最大
        # 对中间的k 我们组合上述两组即可 前半部分差是1到k 后半部分差全部是1

        res = []
        min_one, max_one = 1, k+1
        while min_one < max_one:
            res.append(min_one)
            res.append(max_one)
            min_one, max_one = min_one+1, max_one-1
        if min_one == max_one:
            res.append(min_one)
        tmp = list(range(k+2, n+1))
        res.extend(tmp)
        return res