class Solution:
    def digitCount(self, num: str) -> bool:
        cnt = [0 for i in range(10)]
        for n in num:
            cnt[ord(n) - ord('0')] += 1

        for i in range(len(num)):
            if cnt[i] != ord(num[i]) - ord('0'):
                return False

        return True