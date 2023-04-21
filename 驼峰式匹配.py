class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        n = len(queries)
        ans = [True for i in range(n)]
        for idx in range(n):
            i = 0
            for c in queries[idx]:
                if c.isupper(): # 匹配大写
                    if i == len(pattern) or c != pattern[i]:
                        ans[idx] = False
                        break
                    else:
                        i += 1
                else: # 过小写
                    if i != len(pattern) and pattern[i].islower():
                        if c == pattern[i]:
                            i += 1
            if i != len(pattern): # 匹配完
                ans[idx] = False

        return ans