class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        cur_res = {''}
        idx1, idx2 = 0, 0
        n = len(expression)
        flag = False
        while idx1 < n:
            idx2 = idx1
            if expression[idx1] == '{':
                cnt = 1
                idx2 += 1
                while True:
                    if expression[idx2] == '{':
                        cnt += 1
                    elif expression[idx2] == '}':
                        cnt -= 1
                    if cnt == 0:
                        break
                    idx2 += 1
                nxt_res = self.braceExpansionII(expression[idx1+1:idx2])
                idx1 = idx2+1

            elif expression[idx1] == ',':
                idx1 += 1
                idx2 = idx1
                cnt = 0
                while idx2 < n and (cnt != 0 or expression[idx2] != ','):
                    if expression[idx2] == '{':
                        cnt += 1
                    elif expression[idx2] == '}':
                        cnt -= 1
                    idx2 += 1
                nxt_res = self.braceExpansionII(expression[idx1:idx2])
                idx1 = idx2
                flag = True
            else:
                nxt_res = {expression[idx1]}
                idx1 += 1

            # 合并
            if flag:
                for i in nxt_res:
                    cur_res.add(i)
                flag = False
            # 相接
            else:
                new_res = set()
                for i in cur_res:
                    for j in nxt_res:
                        new_res.add(i+j)
                cur_res = new_res

        return sorted(list(cur_res))


