class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        # 我超 我一开始还以为深搜
        # 其实只要算出来移动的区间 然后找到这个区间里的水果数量就行
        # 只要算先左后右 因为多次改变方向肯定不是最优选择
        presum = [0] * 200001
        idx = 0
        for i in range(200001):
            if idx < len(fruits) and i == fruits[idx][0]:
                presum[i] = presum[i-1]+fruits[idx][1]
                idx += 1
            else:
                presum[i] = presum[i-1]


        res = 0
        for x in range(k//2+1): # 向一个方向走x步，向另一个方向走k-x步
            left1, right1 = startPos-x, startPos-x+k-x
            left2, right2 = startPos+x-(k-x), startPos+x
            if right1 > 200000:
                right1 = 200000
            if right2 > 200000:
                right2 = 200000

            if left1 > 0:
                res = max(res, presum[right1]-presum[left1-1])
            else:
                res = max(res, presum[right1])
            if left2 > 0:
                res = max(res, presum[right2]-presum[left2-1])
            else:
                res = max(res, presum[right2])

        return res

