class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        # 设 dp[i][j] 表示数组 arr1 中的前 i 个元素进行了 j 次替换后组成严格递增子数组末
        # 尾元素的最小值
        # 此时如果 arr1[i] 需要进行保留，则 arr1[i] 一定严格大于前 i−1 个元素替换后组成的
        # 严格递增子数组最末尾的元素。假设前 i−1 个元素经过了 j 次变换后得到的递增子数组的末
        # 尾元素的最小值为 dp[i−1][j]，如果满足 arr1[i]>dp[i−1][j]，则此时 arr1[i] 可
        # 以保留加入到该子数组中且构成的数组严格递增
        # 此时如果 arr1[i] 需要进行替换，则替换后的元素一定严格大于前 i−1 个元素替换后组成
        # 的严格递增子数组最末尾的元素。假设前 i−1 个元素经过了 j−1 次变换后得到的递增子数
        # 组的末尾元素的最小值为 dp[i−1][j−1]，此时我们从 arr2 找到严格大于 dp[i−1][j−1]
        # 的最小元素 arr2[k]，则此时将 arr2[k] 加入到该子数组中且构成数组严格递增。

        arr2 = sorted(set(arr2))
        n1, n2 = len(arr1), len(arr2)
        dp = [[1e10 for i in range(min(n1, n2)+1)] for j in range(n1+1)]
        dp[0][0] = -1
        for i in range(1, n1+1):
            for j in range(min(i, n2) + 1):
                if arr1[i-1] > dp[i-1][j]: # 保留arr1[i]
                    # 这里不需要判断j >= i-1, 因为如果j < i-1, 则arr1[i] 一定 < dp[i-1][j]
                    dp[i][j] = min(dp[i][j], arr1[i-1])

                # 替换arr1[i]
                if dp[i-1][j-1] != 1e10: # i-1替换j-1存在
                    k = bisect_right(arr2, dp[i-1][j-1])
                    if k != n2:
                        dp[i][j] = min(dp[i][j], arr2[k])

                if i == n1 and dp[i][j] != 1e10:
                    return j
        return -1










