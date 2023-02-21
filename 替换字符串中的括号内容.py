class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        know = {}
        for k in knowledge:
            know[k[0]] = k[1]
        idx1, idx2 = 0, 0
        n = len(s)
        res = ''
        while idx1 < n:
            if s[idx1] == '(':
                idx2 = idx1+1
                while s[idx2] != ')':
                    idx2 += 1
                key = s[idx1+1:idx2]
                if key in know:
                    res += know[key]
                else:
                    res += '?'

                idx1 = idx2+1
            else:
                res += s[idx1]
                idx1 += 1

        return res
