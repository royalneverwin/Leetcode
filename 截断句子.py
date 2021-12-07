class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        cnt = 0;
        length = len(s);
        for i in range(1, length):
            if s[i] == ' ':
                cnt += 1;
                if cnt == k:
                    return s[:i];
        return s[:length+1];
