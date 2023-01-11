class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        words = s.split()
        prev = -1
        for word in words:
            if word[0].isdigit():
                cur = int(word)
                if cur > prev:
                    prev = cur
                else:
                    return False
        return True