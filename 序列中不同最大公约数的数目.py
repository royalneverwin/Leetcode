class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        '''
        枚举
        p 为一个序列 A=[a0,a1,⋯,ak] 的最大公约数，令 ai=ci×p，则序列即为 A=[c0×p,c1×p,c2×p,⋯,ck×p]，根据最大公约数的性质可知此时 gcd(a0,a1,a2,⋯,ak)=p，则可以推出 gcd(c0,c1,c2,⋯,ck)=1。此时我们在序列 A 中添加 p 的任意倍数 a_{k+1}=c_{k+1}×p 时，则序列 A 的最大公约数依然为 p，即此时 gcd(a0,a1,a2,⋯,ak,a_{k+1})=p。
        因此 我们可以遍历所有可能的最大公约数 对于每一个可能的最大公约数a 我们从nums中找到所有能够整除a的数 如果这些数的最大公约数就是a 则a就是正确的最大公约数
        注意 如果直接遍历nums会超时 在这里我们把nums存到哈希表中 然后直接遍历可能的最大公约数a的倍数 查看是否在nums中即可
        '''
        res = 0
        n = len(nums)
        flag = set()
        for num in nums:
            flag.add(num)
        max_n = max(nums)
        for i in range(1, max_n+1):
            cur_gcd = None
            for j in range(i, max_n+1, i):
                if j in flag:
                    if cur_gcd == None:
                        cur_gcd = j // i
                    else:
                        cur_gcd = gcd(cur_gcd, j // i)
            if cur_gcd == 1:
                res += 1

        return res
