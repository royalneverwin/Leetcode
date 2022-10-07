class Solution:
    def reformatNumber(self, number: str) -> str:
        idx = 0
        while idx < len(number):
            if number[idx] == ' ' or number[idx] == '-':
                number = number[0:idx] + number[idx+1:]
            else:
                idx += 1

        res = ''
        while len(number) > 4:
            res += number[0:3]
            res += '-'
            number = number[3:]

        if len(number) < 4:
            res += number
        else:
            res += number[0:2] + '-' + number[2:]
        return res
