class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        tmp = num_str
        while len(tmp) > 2:
            max_n = max(tmp)
            if tmp[0] == max_n:
                tmp = tmp[1:]
            else:
                tmp1 = tmp[0]
                idx = -1
                for i in range(len(tmp)):
                    if tmp[i] == max_n:
                        idx = i
                tmp[0] = max_n
                tmp[idx] = tmp1
                break

        if len(tmp) == 2:
            if tmp[0] < tmp[1]:
                tmp1 = tmp[0]
                tmp[0] = tmp[1]
                tmp[1] = tmp1
        return int(''.join((num_str[0:len(num_str) - len(tmp)] + tmp)))