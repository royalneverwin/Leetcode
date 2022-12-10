class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        n, m = len(baseCosts), len(toppingCosts)
        min_dis = 10000000000
        res = None
        for i in range(n):
            dp = {}
            dp[0] = baseCosts[i]
            if abs(dp[0]-target) < min_dis:
                min_dis = abs(dp[0]-target)
                res = dp[0]
            elif abs(dp[0]-target) == min_dis:
                res = min(res, dp[0]) # 返回成本较低的那种

            for j in range(m):
                cur_dp = list(dp.items())
                for key, val in cur_dp:
                    dp[key+(3**j)] = val + toppingCosts[j]
                    if abs((val + toppingCosts[j])-target) < min_dis:
                        min_dis = abs((val + toppingCosts[j])-target)
                        res = val + toppingCosts[j]
                    elif abs((val + toppingCosts[j])-target) == min_dis:
                        res = min(val + toppingCosts[j], res) # 返回成本较低的那种

                    dp[key+2*(3**j)] = val + 2*toppingCosts[j]
                    if abs((val + 2*toppingCosts[j])-target) < min_dis:
                        min_dis = abs((val + 2*toppingCosts[j])-target)
                        res = val + 2*toppingCosts[j]
                    elif abs((val + 2*toppingCosts[j])-target) == min_dis:
                        res = min(val + 2*toppingCosts[j], res) # 返回成本较低的那种


        return res

