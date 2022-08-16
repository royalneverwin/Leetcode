class OrderedStream:

    def __init__(self, n: int):
        self.n = n
        self.ptr = 0
        self.stream = ['' for i in range(n)]

    def insert(self, idKey: int, value: str) -> List[str]:
        self.stream[idKey-1] = value
        ret = []
        if self.ptr == idKey-1:
            while self.ptr < self.n and self.stream[self.ptr] != '':
                ret.append(self.stream[self.ptr])
                self.ptr += 1
        return ret




# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)