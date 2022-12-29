class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        res = ''
        idx1, idx2 = 0, 0
        while idx1 < len(word1) and idx2 < len(word2):
            if ord(word1[idx1]) < ord(word2[idx2]):
                res += word2[idx2]
                idx2 += 1
            elif ord(word1[idx1]) > ord(word2[idx2]):
                res += word1[idx1]
                idx1 += 1
            else:
                tmp = 1
                flag = None
                while idx1+tmp < len(word1) and idx2+tmp < len(word2):
                    if ord(word1[idx1+tmp]) < ord(word2[idx2+tmp]):
                        flag = False
                        break
                    elif ord(word1[idx1+tmp]) > ord(word2[idx2+tmp]):
                        flag = True
                        break
                    else:
                        tmp += 1
                if idx1+tmp == len(word1):
                    res += word2[idx2]
                    idx2 += 1
                elif idx2+tmp == len(word2):
                    res += word1[idx1]
                    idx1 += 1
                else:
                    if flag:
                        res += word1[idx1]
                        idx1 += 1
                    else:
                        res += word2[idx2]
                        idx2 += 1

        while idx1 < len(word1):
            res += word1[idx1]
            idx1 += 1
        while idx2 < len(word2):
            res += word2[idx2]
            idx2 += 1

        return res