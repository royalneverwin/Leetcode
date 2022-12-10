class FreqStack:

    def __init__(self):
        self.st = []
        self.cnt = {}
        self.freq = defaultdict(set)

    def push(self, val: int) -> None:
        self.st.append(val)
        if val in self.cnt:
            prev_cnt = self.cnt[val]
            self.cnt[val] += 1
            self.freq[prev_cnt].remove(val)
            self.freq[prev_cnt+1].add(val)
        else:
            self.cnt[val] = 1
            self.freq[1].add(val)

    def pop(self) -> int:
        max_cnt = max(self.freq.keys())
        idx = len(self.st)-1
        res = None
        while idx >= 0:
            if self.st[idx] in self.freq[max_cnt]: # 删除
                res = self.st.pop(idx)
                break
            else:
                idx -= 1

        self.freq[max_cnt].remove(res)
        if len(self.freq[max_cnt]) == 0:
            self.freq.pop(max_cnt)
        if max_cnt > 1:
            self.freq[max_cnt-1].add(res)
            self.cnt[res] -= 1
        else:
            self.cnt.pop(res)
        return res



# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()