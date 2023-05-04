class Solution:
    def lastSubstring(self, s: str) -> str:
        # 一定是一个后缀
        # 就看哪个后缀更大
        n = len(s)
        res = ''
        idx = 1
        ch = max(s)
        for i in range(n):
            if s[i] == ch:
                res = max(s[i:], res)


        return res


        # 摆了。。。 暴力求解
        # 最讨厌类似KMP的算法，一辈子看不明白
        # 题解都不想看z