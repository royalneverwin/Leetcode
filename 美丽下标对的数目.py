class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        for i in range(n-1):
            for j in range(i+1, n):
                a = int(str(nums[i])[0])
                b = int(str(nums[j])[-1])
                if gcd(a, b) == 1:
                    cnt += 1 
        
        return cnt
