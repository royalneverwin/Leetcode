class  P():
    def __init__(self,a,b):
        self.a = a
        self.b = b
    def __lt__(self, other): # 重写比较函数
        if self.b > other.b:
            return True
        else:
            return False

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        cnt = [0] * 10001
        n = len(barcodes)
        for i in range(n):
            cnt[barcodes[i]] += 1
        res = []
        p_list = []
        for i, c in enumerate(cnt):
            heapq.heappush(p_list, P(i, c))
        while True:
            cur_p1 = heapq.heappop(p_list)
            a = cur_p1.a
            b = cur_p1.b
            if b == 0:
                break
            res.append(a)
            b -= 1
            cur_p2 = heapq.heappop(p_list)
            c = cur_p2.a
            d = cur_p2.b
            if d == 0:
                assert(b == 0)
                break
            res.append(c)
            d -= 1
            heapq.heappush(p_list, P(a, b))
            heapq.heappush(p_list, P(c, d))

        return res