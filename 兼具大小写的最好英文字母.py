class Solution:
    def greatestLetter(self, s: str) -> str:
        small = [False for i in range(26)]
        big = [False for i in range(26)]
        for c in s:
            if c.islower():
                small[ord(c) - ord('a')] = True
            else:
                big[ord(c) - ord('A')] = True

        for i in range(25, -1, -1):
            if small[i] and big[i]:
                return chr(ord('A')+i)

        return ''
