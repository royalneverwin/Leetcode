class StockSpanner:

    def __init__(self):
        self.st = [(1000000, -1)]
        self.idx = 0


    def next(self, price: int) -> int:
        while self.st[-1][0] <= price: # 单调栈
            self.st.pop()
        res = self.idx - self.st[-1][1]
        self.st.append((price, self.idx))
        self.idx += 1
        return res


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)