class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        name_time = defaultdict(list)
        n = len(keyName)
        for i in range(n):
            cur_time = int(keyTime[i][:2]) * 60 + int(keyTime[i][3:])
            name_time[keyName[i]].append(cur_time)

        res = []
        for key, val in name_time.items():
            val.sort()
            prev_idx = 0
            n = len(val)
            cnt = 1
            for i in range(1, n):
                if val[i]-val[prev_idx] <= 60:
                    cnt += 1
                    if cnt == 3:
                        res.append(key)
                        break
                else:
                    prev_idx += 1
                    if i != prev_idx and val[i]-val[prev_idx] <= 60:
                        cnt = 2
                    elif i != prev_idx:
                        prev_idx += 1
                        cnt = 1
                    else:
                        cnt = 1
        return sorted(res)