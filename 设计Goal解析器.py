class Solution:
    def interpret(self, command: str) -> str:
        res = ''
        flag = False
        for i in command:
            if i == 'G':
                res += i
            elif i == 'a':
                flag = True
            elif i == ')':
                if flag:
                    res += 'al'
                    flag = False
                else:
                    res += 'o'
        return res