class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        res = []
        def DFS(s, idx):
            if idx == len(s):
                nonlocal res
                res.append(s)
            else:
                if s[idx].isalpha():
                    DFS(s, idx+1)
                    DFS(s[0:idx]+s[idx].swapcase()+s[idx+1:], idx+1)
                else:
                    DFS(s, idx+1)
        DFS(s, 0)
        return res

            