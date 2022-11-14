class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        ls = ['a','e','i','o','u','A','E','I','O','U']
        a = s[:len(s)//2]
        b = s[len(s)//2:]
        cnt1, cnt2 = 0, 0
        for i in a:
            if i in ls:
                cnt1 += 1
        for i in b:
            if i in ls:
                cnt2 += 1

        return True if cnt1==cnt2 else False
