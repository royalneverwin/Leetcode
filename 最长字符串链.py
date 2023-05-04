def is_prev(word1, word2):
    assert(len(word1) < len(word2))
    idx1, idx2 = 0, 0
    flag = False
    while idx2 < len(word2):
        if idx1 == len(word1):
            if flag == True:
                return False
            else:
                flag == True
                idx2 += 1
                continue

        if word2[idx2] == word1[idx1]:
            idx1, idx2 = idx1+1, idx2+1
        elif flag == False:
            flag = True
            idx2 += 1
        else:
            return False

    if idx1 == len(word1):
        return True

class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda x: len(x))
        n = len(words)
        dp = [1 for i in range(n)]

        for i in range(n):
            for j in range(i):
                if len(words[j]) == len(words[i])-1:
                    if is_prev(words[j], words[i]):
                        dp[i] = max(dp[i], dp[j]+1)

        return max(dp)
