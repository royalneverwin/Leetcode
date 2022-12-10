class Solution:
    def secondHighest(self, s: str) -> int:
        res = None
        max_c = None
        for c in s:
            if c >= '0' and c <= '9':
                if max_c == None:
                    max_c = c
                else:
                    if max_c < c:
                        res = max_c
                        max_c = c
                    elif max_c > c:
                        if res == None:
                            res = c
                        elif res < c:
                            res = c
        return int(res) if res else -1
