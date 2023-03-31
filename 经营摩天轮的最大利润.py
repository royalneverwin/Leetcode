class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        cur_cus = 0
        n = len(customers)
        cur_pro = 0
        max_pro = 0
        res = -1
        cur_done = 0
        for i in range(n):
            cur_cus += customers[i]
            new_one = min(cur_cus, 4)
            cur_cus -= new_one
            cur_pro += new_one * boardingCost - runningCost
            cur_done += 1
            if cur_pro >max_pro:
                res = cur_done
                max_pro = cur_pro

        while cur_cus > 0:
            new_one = min(cur_cus, 4)
            cur_cus -= new_one
            cur_pro += new_one * boardingCost - runningCost
            cur_done += 1
            if cur_pro >max_pro:
                res = cur_done
                max_pro = cur_pro

        return res