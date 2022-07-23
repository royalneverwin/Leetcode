class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        ret1 = 0
        idx = start
        n = len(distance)
        while idx != destination:
            ret1 += distance[idx]
        idx = (idx + 1) % n

        ret2 = 0
        idx = start
        while idx != destination:
            ret2 += distance[(idx - 1) % n]
        idx = (idx - 1) % n

        return min(ret1, ret2)

