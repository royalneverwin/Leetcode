class Solution:
    def reachNumber(self, target: int) -> int:
        # target有对称性 考虑>0即可
        # if target == sum(1-k) 直接得到ans k
        # if target<sum(1-k) 令delta = sum - target 如果delta是奇数 则检查sum(1-(k+1))/sum(1-(k+2)) 找到偶数的delta
        # 若 delta是偶数，我们找到1到k的几个和 使得和为delta/2
        # 如果k < delta/2 则先找一个k 再从剩下的里面找delta/2-k
        # 如歌k >= delta/2 则可以直接找到delta/2
        # 总之 只要delta是偶数 就一定能找到
        target = abs(target)
        idx = 1
        sum = 0
        while sum < target:
            sum += idx
            idx += 1
        if sum == target:
            return idx-1
        else:
            delta = sum - target
            if delta % 2 != 0:
                delta += idx
                idx += 1
                if delta % 2 != 0:
                    delta += idx
                    idx += 1
            return idx-1