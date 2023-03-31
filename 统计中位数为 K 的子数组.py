class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        # 经典的前缀和+hash
        n = len(nums)
        idx = -1
        preSum = [0 for i in range(n+1)]
        sum_list = {0: [preSum[0]]}
        for i in range(n):
            if nums[i] > k:
                preSum[i+1] = preSum[i]+1
            elif nums[i] < k:
                preSum[i+1] = preSum[i]-1
            else:
                idx = i
                preSum[i+1] = preSum[i]

            if preSum[i+1] in sum_list:
                sum_list[preSum[i+1]].append(i+1)
            else:
                sum_list[preSum[i+1]] = [i+1]

        res = 0
        for key, val in sum_list.items(): # = 0 len就一定会是奇数
            less, greater = 0, 0
            for v in val:
                if v <= idx:
                    less += 1
                else:
                    greater += 1
            res += less * greater
        for key in sum_list.keys(): # len为偶数的情况下
            if key+1 in sum_list: # key中的在左侧，key+1中的在右侧
                less, greater = 0, 0
                for i in sum_list[key]:
                    if i <= idx:
                        less += 1
                for j in sum_list[key+1]:
                    if j > idx:
                        greater += 1
                res += less*greater


        return res
