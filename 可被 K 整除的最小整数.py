class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        # 111 = 11 * 10 + 1
        # 只要记录111 % k 的余数r，计算下一个时候就是r*10+1 % k
        # 记录r出现的次数 如果r重复出现 那就不可能有解

        res = 1
        cur = 1
        my_hash = set()
        while True:
            r = cur % k
            if r == 0:
                return res
            elif r in my_hash:
                return -1
            else:
                my_hash.add(r)
                cur = r * 10 + 1
                res += 1



