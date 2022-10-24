class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        class point:
            def __init__(self, num, idx):
                self.num = num
                self.idx = idx

        def key(p):
            return p.num

        nums2_new = []
        for i in range(len(nums2)):
            nums2_new.append(point(nums2[i], i))

        nums1.sort()
        nums2_new.sort(key=key)
        idx1, idx2 = 0, 0
        res = [-1 for i in range(len(nums1))]
        left = []
        while idx1 < len(nums1) and idx2 < len(nums2):
            if nums1[idx1] > nums2_new[idx2].num:
                res[nums2_new[idx2].idx] = nums1[idx1]
                idx2 += 1
            else:
                left.append(nums1[idx1])
            idx1 += 1

        idx1, idx2 = 0, 0
        while idx1 < len(nums1):
            if res[idx1] == -1:
                res[idx1] = left[idx2]
                idx2 += 1
            idx1 += 1

        return res

