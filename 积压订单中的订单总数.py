from sortedcontainers import SortedDict
class Solution:
    def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
        MOD = 1000000000+7
        buy = SortedDict()
        sell = SortedDict()
        n = len(orders)
        for i in range(n):
            if orders[i][2] == 0: # buy
                if len(sell) > 0:
                    p = sell.keys()[0]
                else:
                    p = 1e9

                while p <= orders[i][0] and orders[i][1] > sell[p]: # 还有buy
                    orders[i][1] -= sell[p]
                    del sell[p]
                    if len(sell) > 0:
                        p = sell.keys()[0]
                    else:
                        p = 1e9

                if p <= orders[i][0] and orders[i][1] == sell[p]:
                    del sell[p]
                elif p <= orders[i][0] and orders[i][1] < sell[p]:
                    sell[p] -= orders[i][1]
                else:
                    if orders[i][0] in buy:
                        buy[orders[i][0]] += orders[i][1]
                    else:
                        buy[orders[i][0]] = orders[i][1]

            else: # sell
                if len(buy) > 0:
                    p = buy.keys()[-1]
                else:
                    p = -1
                while p >= orders[i][0] and orders[i][1] > buy[p]: # 还有sell
                    orders[i][1] -= buy[p]
                    del buy[p]
                    if len(buy) > 0:
                        p = buy.keys()[-1]
                    else:
                        p = -1

                if p >= orders[i][0] and orders[i][1] == buy[p]:
                    del buy[p]
                elif p >= orders[i][0] and orders[i][1] < buy[p]:
                    buy[p] -= orders[i][1]
                else:
                    if orders[i][0] in sell:
                        sell[orders[i][0]] += orders[i][1]
                    else:
                        sell[orders[i][0]] = orders[i][1]
        res = 0
        for key, val in sell.items():
            res = (res+val) % MOD
        for key, val in buy.items():
            res = (res+val) % MOD

        return res