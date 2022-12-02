class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        # 可以选字母组进行扩张！
        res = 0
        for word in words:
            idx1, idx2 = 0, 0
            flag = True
            while idx1 < len(s) and idx2 < len(word):
                cnt1, cnt2 = 1, 1
                while idx1+1 < len(s) and s[idx1] == s[idx1+1]:
                    idx1 += 1
                    cnt1 += 1
                while idx2+1 < len(word) and word[idx2] == word[idx2+1]:
                    idx2 += 1
                    cnt2 += 1
                if s[idx1] != word[idx2] or cnt2 > cnt1 or (cnt2 < cnt1 and cnt1 == 2):
                    flag = False
                    break
                idx1, idx2 = idx1+1, idx2+1

            if flag and idx1 == len(s) and idx2 == len(word):
                res += 1


        return res