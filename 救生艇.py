class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        n = len(people)
        people.sort()
        left, right = 0, n-1
        cnt = 0
        while left < right:
            if people[left]+people[right] <= limit:
                left, right, cnt = left+1, right-1, cnt+1
            else:
                right, cnt = right-1, cnt+1

        if left == right:
            cnt += 1
        
        return cnt
