class Solution:
    def reformat(self, s: str) -> str:
        is_letter = False
        s = list(s)
        if s[0].isalpha():
            is_letter = True
        idx1, idx2 = 1, 2
        while idx1 < len(s):
            if is_letter:
                if s[idx1].isalpha():
                    while idx2 < len(s) and s[idx2].isalpha():
                        idx2 += 1
                    if idx2 == len(s):
                        if idx1 == len(s)-1: # 只多了这一个
                            if s[0].isdigit(): # 可以放最前面
                                s.insert(0, s[idx1])
                                s.pop(idx1+1)
                                return ''.join(s)
                        return ''

                    s.insert(idx1, s[idx2])
                    s.pop(idx2+1)
                is_letter = False
                idx1 += 1
                idx2 = idx1+1

            else:
                if s[idx1].isdigit():
                    while idx2 < len(s) and s[idx2].isdigit():
                        idx2 += 1
                    if idx2 == len(s):
                        if idx1 == len(s)-1: # 只多了这一个
                            if s[0].isalpha(): # 可以放最前面
                                s.insert(0, s[idx1])
                                s.pop(idx1+1)
                                return ''.join(s)
                        return ''

                    s.insert(idx1, s[idx2])
                    s.pop(idx2+1)
                is_letter = True
                idx1 += 1
                idx2 = idx1+1

        return ''.join(s)