class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        cnt = {'c':0, 'r':0, 'o':0, 'a':0, 'k':0}
        res = 0
        cur = 0
        for i in croakOfFrogs:
            if i == 'c':
                cnt['c'] += 1
                cur += 1
                res = max(res, cur)
            elif i == 'r':
                if cnt['c'] == 0:
                    return -1
                else:
                    cnt['c'] -= 1
                    cnt['r'] += 1
            elif i == 'o':
                if cnt['r'] == 0:
                    return -1
                else:
                    cnt['r'] -= 1
                    cnt['o'] += 1
            elif i == 'a':
                if cnt['o'] == 0:
                    return -1
                else:
                    cnt['o'] -= 1
                    cnt['a'] += 1
            elif i == 'k':
                if cnt['a'] == 0:
                    return -1
                else:
                    cnt['a'] -= 1
                    cnt['k'] += 1
                    cur -= 1
        if cnt['c'] > 0 or cnt['r'] > 0 or cnt['o'] > 0 or cnt['a'] > 0:
            return -1
        return res
