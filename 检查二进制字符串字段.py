class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        flag = True
        prev = None
        for i in s:
            if i == '1':
                if prev == None: # 一定是第一个1
                    flag = False
                elif prev == '0':
                    if not flag:
                        return False
                    else:
                        flag = False
            prev = i

        return True


