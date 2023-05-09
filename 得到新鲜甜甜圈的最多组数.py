class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        # 状态压缩
        # 转变为0 - batchsize-1及对应的个数
        # 每个个数不超过30
        # 所以可以用5位数字表示
        # 0数字可以不表示
        # 可以用（batchsize-1）* 5位数表示状态进行动态规划
        n = len(groups)
        cnt = [0] * batchSize
        for i in range(n):
            groups[i] %= batchSize
            cnt[groups[i]] += 1

        # 创建status
        status = 0
        for i in range(1, batchSize):
            status |= cnt[i] << (5 * (i-1))

        @cache
        def dp(status):
            if status == 0:
                return 0
            nonlocal batchSize
            cur_sum = 0
            for i in range(1, batchSize):
                cur_sum += ((status >> (5 * (i-1))) & 0x1f) * i
            res = 0
            for i in range(1, batchSize):
                cur = (status >> (5 * (i-1))) & 0x1f
                if cur > 0:
                    new_status = status - (1 << (5 * (i-1)))
                    if (cur_sum-i) % batchSize == 0:
                        res = max(res, dp(new_status)+1)
                    else:
                        res = max(res, dp(new_status))

            return res

        return dp(status)+cnt[0]




        