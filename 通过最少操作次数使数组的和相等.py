class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        sum1 = sum(nums1)
        sum2 = sum(nums2)
        if sum1 == sum2:
            return 0
        elif sum1 > sum2: # 换成nums1 < nums2
            tmp = nums1
            nums1 = nums2
            nums2 = tmp
        n1, n2 = len(nums1), len(nums2)

        change_ls = {0:0,1:0,2:0,3:0,4:0,5:0}
        for i in range(n1):
            change_ls[6 - nums1[i]] += 1
        for i in range(n2):
            change_ls[nums2[i] - 1] += 1

        cur = abs(sum1 - sum2)
        key = 5
        res = 0
        while cur > 0 and key > 0:
            if key * change_ls[key] >= cur:
                res += cur // key
                if cur % key != 0:
                    res += 1
                cur = 0
                break
            else:
                res += change_ls[key]
                cur -= key * change_ls[key]
                key -= 1

        if cur > 0:
            return -1
        return res