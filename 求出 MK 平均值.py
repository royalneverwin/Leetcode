from sortedcontainers import SortedList

class MKAverage:

    def __init__(self, m: int, k: int):
        self.s1 = SortedList() # 前k个小的
        self.s2 = SortedList() # 中间m-2k
        self.s3 = SortedList() # 后k个大的
        self.sum = -1
        self.q = deque()
        self.m = m
        self.k = k
    def addElement(self, num: int) -> None:
        if len(self.q) < self.m:
            self.q.append(num)
            self.s2.add(num)
            if len(self.q) == self.m:
                for i in range(self.k):
                    self.s1.add(self.s2.pop(0))
                    self.s3.add(self.s2.pop())
                self.sum = sum(self.s2)
        else:
            self.q.append(num)
            if num < self.s1[-1]: # 放在s1中
                new_num = self.s1.pop()
                self.s2.add(new_num)
                self.s1.add(num)
                self.sum += new_num
            elif num > self.s3[0]: # 放在s3中
                new_num = self.s3.pop(0)
                self.s2.add(new_num)
                self.s3.add(num)
                self.sum += new_num
            else:
                self.s2.add(num)
                self.sum += num
            # 目前s2多一个
            pop_num = self.q.popleft()
            if pop_num in self.s1:
                remove_num = self.s2.pop(0)
                self.sum -= remove_num
                self.s1.remove(pop_num)
                self.s1.add(remove_num)
            elif pop_num in self.s3:
                remove_num = self.s2.pop()
                self.sum -= remove_num
                self.s3.remove(pop_num)
                self.s3.add(remove_num)
            else:
                self.sum -= pop_num
                self.s2.remove(pop_num)

    def calculateMKAverage(self) -> int:
        if self.sum == -1:
            return -1
        else:
            return self.sum // (self.m - 2*self.k)



# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()