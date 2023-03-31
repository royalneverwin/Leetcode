class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        n = len(hours)
        cnt = [0 for i in range(n)]
        if hours[0] > 8:
            cnt[0] = 1
        else:
            cnt[0] = -1
        for i in range(1, n):
            if hours[i] > 8:
                cnt[i] = cnt[i-1] + 1
            else:
                cnt[i] = cnt[i-1] - 1
        # 锁定r找l
        # 注意 如果l1 < l2且cnt[l1] < cnt[l2]则l2一定不会作为答案（对任意的r）
        # 所以维护一个栈 用来排除不需要的l2 栈顶元素cnt最小，l最大
        # 注意 如果r1 < r2 且 cnt[r1] < cnt[r2] 则r1一定不会作为答案（对任意的l）
        # 所以从大到小遍历r
        # 太巧妙了！
        res = 0
        stk = [(-1, 0)]
        for i in range(n):
            if stk[0][1] > cnt[i]:
                stk.insert(0, (i, cnt[i]))

        for i in range(n-1, -1, -1):
            while len(stk) > 0 and cnt[i] > stk[0][1]:
                res = max(res, i-stk[0][0])
                stk.pop(0)

            if len(stk) == 0:
                break

        return res
