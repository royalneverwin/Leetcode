class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s = s[1:len(s)-1]
        res = []
        def getnum(s):
            if len(s) == 1:
                return [s]
            else:
                if s[0] == '0' and s[-1] == '0':
                    return []
                elif s[-1] == '0':
                    return [s]
                elif s[0] == '0':
                    return [s[0:1]+'.'+s[1:]]
                else:
                    res = [s]
                    for l in range(1, len(s)):
                        res.append(s[0:l]+'.'+s[l:])
                    return res

        for i in range(1, len(s)):
            num1 = getnum(s[0:i])
            num2 = getnum(s[i:])
            for n1 in num1:
                for n2 in num2:
                    res.append('('+n1+', '+n2+')')

        return res
