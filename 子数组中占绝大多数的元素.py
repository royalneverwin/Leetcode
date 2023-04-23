class MajorityChecker:
    # 看题解了。。。
    # 竟然是不保证一定正确的算法，难崩啊
    # 随机+二分

    k = 30
    def __init__(self, arr: List[int]):
        self.arr = arr
        self.idx_list = defaultdict(list)

        for idx, num in enumerate(arr):
            self.idx_list[num].append(idx)

    def query(self, left: int, right: int, threshold: int) -> int:

        length = right-left+1
        for i in range(self.k):
            num = self.arr[randint(left, right)]
            val = self.idx_list[num]
            right_idx = bisect_right(val, right)
            left_idx = bisect_left(val, left)
            if right_idx-left_idx >= threshold: # 找到了
                return num
            elif (right_idx-left_idx) * 2 >= length: # 不可能找到
                return -1
        return -1




# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)