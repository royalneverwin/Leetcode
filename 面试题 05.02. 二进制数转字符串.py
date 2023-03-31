class Solution:
    def printBin(self, num: float) -> str:
        res = '0.'
        cnt = 0
        while num != 0:
            if cnt == 6:
                return 'ERROR'
            num *= 2
            new_num = int(num)
            num = num-new_num
            res += str(new_num)
            cnt +=1
        return res