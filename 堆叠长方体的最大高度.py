class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        # 由于题目要求长方体的高度最大，由此很容易想到将每个长方体的最长边做为高度是最优的，但这种堆叠方法是
        # 否正确需要进一步思考。
        # 反证法可以证得重新排列w，l，h使得h最大不会影响长方体的堆叠
        # 然后就是简单的dp 非常简单
        for cuboid in cuboids:
            cuboid.sort()
        cuboids.sort(key=sum)

        n = len(cuboids)
        dp = [cuboids[i][2] for i in range(n)]
        for i in range(1,n):
            for j in range(i):
                if cuboids[j][0] <= cuboids[i][0] and cuboids[j][1] <= cuboids[i][1] \
                        and cuboids[j][2] <= cuboids[i][2]:
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2])

        return max(dp)


