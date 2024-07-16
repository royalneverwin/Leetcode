from queue import PriorityQueue

class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        num = PriorityQueue()
        for n in nums:
            num.put(n)
        res = []
        while not num.empty():
            nums1 = num.get()
            nums2 = num.get()
            res.append(nums2)
            res.append(nums1)
        
        return res

