class Solution:
    def equalFrequency(self, word: str) -> bool:
        # 离谱。。
        cnt = [0] * 26
        std = 0
        for c in word:
            cnt[ord(c)-ord('a')] += 1

        # 全1
        flag = True
        for i in range(26):
            if cnt[i] != 0 and cnt[i] != 1:
                flag = False
                break
        if flag:
            return True

        # 单字符
        tmp = 0
        for i in range(26):
            if cnt[i] != 0:
                tmp += 1
        if tmp == 1:
            return True

        # 只有一个1 其他相同
        tmp = 0
        cur = None
        flag = True
        for i in range(26):
            if cnt[i] != 0 and cnt[i] == 1:
                tmp += 1
            elif cnt[i] != 0 and cnt[i] != 1:
                if cur == None:
                    cur = cnt[i]
                elif cur != cnt[i]:
                    flag = False
                    break
        if tmp == 1 and flag:
            return True

        # 只有两个
        tmp = 0
        for i in range(26):
            if cnt[i] != 0:
                tmp += 1
        if tmp == 2:
            new_cnt = list(set(cnt))
            new_cnt.sort()
            if len(new_cnt) == 3 and new_cnt[2]-new_cnt[1] == 1:
                return True
            else:
                return False

        # 正常
        if cnt[0] == cnt[1]:
            std = cnt[0]
        else:
            for i in range(2, 26):
                if cnt[i] != 0:
                    std = cnt[i]
                    break
        flag = False
        for i in range(26):
            if cnt[i] != 0 and cnt[i] != std:
                if flag == False and cnt[i]-std == 1:
                    flag = True
                else:
                    return False

        return flag





        