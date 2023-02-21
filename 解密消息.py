class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        my_dict = {}
        idx = 0
        for c in key:
            if c not in my_dict and c != ' ':
                my_dict[c] = chr(idx+ord('a'))
                idx += 1

        res = ''
        for c in message:
            if c == ' ':
                res += c
            else:
                res += my_dict[c]

        return res