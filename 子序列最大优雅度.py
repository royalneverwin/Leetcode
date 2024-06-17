class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        # 贪心
        # 首先选择profit最多的k个
        # 再从剩下的里面选进行替换 一定是新种类 并且从多的种类个数中扔掉一个profit最少的
        # 注意这个要一直尝试 因为可能一开始替换是亏的 但是替换多了就赚了
        # e.g. [[10,1],[10,1],[10,1],[10,1],[10,1],[10,1],[10,1],[10,1],[10,1],[10,1],[3,2],[3,3],[3,4],[3,5],[3,6],[3,7],[3,8],[3,9],[3,10],[3,11]]
        items.sort(key=lambda x: x[0], reverse=True)
        
        n = len(items)

        # 选前k个
        res = 0
        distinct = 0
        total_profit = 0
        cnt_dict = defaultdict(int)

        for i in range(k):
            if cnt_dict[items[i][1]] == 0:
                distinct += 1

            cnt_dict[items[i][1]] += 1
            total_profit += items[i][0]
        
        res = total_profit + distinct ** 2
        # try to replace
        idx = k-1
        for i in range(k, n):
            if cnt_dict[items[i][1]] > 0: # 未新增种类
                continue

            while idx >= 0 and cnt_dict[items[idx][1]] == 1:
                idx -= 1
            
            if idx == -1:
                break
            
            # 找到应该替换的item
            total_profit = total_profit-items[idx][0]+items[i][0]
            distinct += 1
            res = max(res, total_profit+distinct**2)
            cnt_dict[items[idx][1]] -= 1
            cnt_dict[items[i][1]] += 1
            idx -= 1

        return res
