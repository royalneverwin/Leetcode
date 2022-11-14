class Solution:
    def customSortString(self, order: str, s: str) -> str:
        s = list(s)
        def fun(a):
            nonlocal order
            if a in order:
                return order.index(a)
            else:
                return 26

        s.sort(key=fun)
        return ''.join(s)