class MyCircularDeque:


    def __init__(self, k: int):
        self.queue = []
        self.k = k
        self.cur = 0

    def insertFront(self, value: int) -> bool:
        if self.cur == self.k:
            return False

        self.queue.insert(0, value)
        self.cur += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.cur == self.k:
            return False

        self.queue.append(value)
        self.cur += 1
        return True


    def deleteFront(self) -> bool:
        if self.cur == 0:
            return False

        self.cur -= 1
        self.queue.pop(0)
        return True

    def deleteLast(self) -> bool:
        if self.cur == 0:
            return False

        self.cur -= 1
        self.queue.pop()
        return True

    def getFront(self) -> int:
        if self.cur == 0:
            return -1

        return self.queue[0]

    def getRear(self) -> int:
        if self.cur == 0:
            return -1

        return self.queue[-1]

    def isEmpty(self) -> bool:
        return self.cur == 0

    def isFull(self) -> bool:
        return self.cur == self.k


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()