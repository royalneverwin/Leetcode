class Solution:
    def repeatedCharacter(self, s: str) -> str:
        cnt = [0 for i in range(26)]
        for c in s:
            cnt[ord(c)-ord('a')] += 1
            if cnt[ord(c)-ord('a')] == 2:
                return c
        return -1
