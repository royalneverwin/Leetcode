class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans1, ans2 = 0, 0
        n = len(nums1)
        m = len(nums2)
        for i in range(n):
                if nums1[i] in nums2:
                    ans1 += 1
        
        for i in range(m):
            if nums2[i] in nums1:
                ans2 += 1
            
        return [ans1, ans2]
