class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        l = len(code)
        res = [0 for i in range(l)]
        if k == 0:
            return res

        sum = 0
        if k > 0:
            idx = 1
            cnt = 0
            while cnt < k:
                sum += code[idx]
                cnt += 1
                idx = (idx+1) % l
            res[0] = sum
            index = 1
            while index < l:
                sum -= code[index]
                sum += code[idx]
                res[index] = sum
                idx = (idx+1) % l
                index += 1

        else:
            k = -k
            idx = l-1
            cnt = 0
            while cnt < k:
                sum += code[idx]
                cnt += 1
                idx = (idx-1) % l
            idx = (idx + 1) % l
            res[0] = sum
            index = 1
            while index < l:
                sum -= code[idx]
                sum += code[index-1]
                res[index] = sum
                idx = (idx+1) % l
                index += 1

        return res


