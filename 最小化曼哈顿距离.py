from sortedcontainers import SortedList

class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        s1 = SortedList(p[0]-p[1] for p in points)
        s2 = SortedList(p[0]+p[1] for p in points)

        res = float('inf')

        for p in points:
            s1.remove(p[0]-p[1])
            s2.remove(p[0]+p[1])

            res = min(res, max(s1[-1]-s1[0], s2[-1]-s2[0]))
            
            s1.add(p[0]-p[1])
            s2.add(p[0]+p[1])
        
        return res
