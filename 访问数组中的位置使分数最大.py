class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        # 注意 可以不选nums[i]后面的 所以有三种可能，要注意判断
        n = len(nums)
        dp = [[0, 0] for i in range(n)]
        # dp[i][0]表示偶数访问i个及以后的分数的最大值
        # dp[i][1]表示奇数访问i个即以后的分数的最大值
        if nums[n-1] % 2 ==0: # 偶数
            dp[n-1][0] = nums[n-1]
            dp[n-1][1] = nums[n-1]-x
        else:
            dp[n-1][1] = nums[n-1]
            dp[n-1][0] = nums[n-1]-x

        for i in range(n-2, 0, -1):
            if nums[i] % 2 == 0: # 偶数
                dp[i][0] = max(nums[i]+dp[i+1][0], nums[i]) # = max(max(nums[i]+dp[i+1][0], dp[i+1][0]), nums[i])
                dp[i][1] = max(max(nums[i]+dp[i+1][0]-x, dp[i+1][1]), nums[i]-x)
            else:
                dp[i][1] = max(nums[i]+dp[i+1][1], nums[i])
                dp[i][0] = max(max(nums[i]+dp[i+1][1]-x, dp[i+1][0]), nums[i]-x)
        # for i in range(n-1, 0, -1):
        #     print(i, dp[i])
        if nums[0] % 2 == 0:
            return max(nums[0] + dp[1][0], nums[0])
        else:
            return max(nums[0] + dp[1][1], nums[0])
            

                


