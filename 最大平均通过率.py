class Rate:
    __slots__ = 'p', 't'

    def __init__(self, p: int, t: int):
        self.p = p
        self.t = t


    def __lt__(self, other: 'Rate') -> bool:
        return (self.t+1) * (self.t) * (other.t-other.p) < \
               (other.t+1) * (other.t) * (self.t-self.p)

class Solution:


    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        my_heap = [Rate(*c) for c in classes]
        heapify(my_heap)
        for _ in range(extraStudents):
            heapreplace(my_heap, Rate(my_heap[0].p+1, my_heap[0].t+1))

        res = 0
        for i in my_heap:
            res += i.p / i.t

        return res / len(classes)