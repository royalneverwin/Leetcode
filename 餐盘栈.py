from sortedcontainers import *
class DinnerPlates:
    # 有序集合 使用sortedcontainers 的 SortedSet（第一次听说奥）
    def __init__(self, capacity: int):
        self.stack = []
        self.top = [] # 用来记录每个栈的顶部元素的位置
        self.popIdx = SortedSet()
        self.capacity = capacity

    def push(self, val: int) -> None:
        if not self.popIdx: # 没有空的popIdx
            pos = len(self.stack)
            self.stack.append(val)
            idx = pos // self.capacity
            if pos % self.capacity == 0: # top要push了
                self.top.append(0) # 最新的元素在位置0
            else:
                self.top[idx] += 1 # 位置+1

        else: # 优先一定是放到popIdx中idx最小的位置
            pos = self.popIdx.pop(0)
            self.stack[pos] = val
            idx = pos // self.capacity
            self.top[idx] += 1

    def pop(self) -> int:
        pos = len(self.stack)-1
        while self.popIdx and pos == self.popIdx[-1]:
            self.popIdx.pop()
            self.stack.pop()
            pos -= 1
        if pos == -1:
            return -1
        else:
            self.top[pos//self.capacity] -= 1
            return self.stack.pop()



    def popAtStack(self, index: int) -> int:
        # 不是真正的pop 只是返回数字 并记录pop的位置
        if index >= len(self.top): # 没这么多
            return -1
        elif self.top[index] == -1: # 空的
            return -1
        else:
            pos = index * self.capacity + self.top[index]
            self.popIdx.add(pos)
            self.top[pos//self.capacity] -= 1
            return self.stack[pos]


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)