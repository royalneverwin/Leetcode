class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        # 分治
        # 对于一个特殊序列而言，它一定以 1 开始，以 0 结束，并且1和0不可能在特殊子序列中
        # 因此，我们可以把首位 1 和末位 0 直接移除，进一步考虑剩余的字符串 进行特殊序列的拆分
        if len(s) == 2 or len(s) == 0:
            return s

        begin, end = 0, len(s)-1
        idx1, idx2, counter = begin, begin, 0

        special_lst = []
        while idx2 <= end:
            if s[idx2] == '1':
                counter += 1
            else:
                counter -= 1
            if counter == 0 and idx2 != begin:
                if idx1 == begin and idx2 == end: # 说明整体是一个序列 就要进行特殊处理
                    return '1'+self.makeLargestSpecial(s[begin+1:end])+'0'
                special_lst.append(self.makeLargestSpecial(s[idx1:idx2+1]))
                idx1, idx2 = idx2+1, idx2+1
            else:
                idx2 += 1

        special_lst.sort(reverse=True)
        print(special_lst)
        ret = ''
        for i in special_lst:
            ret += i
        return ret

