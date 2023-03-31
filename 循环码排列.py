class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        # 其实就是正常的格雷编码
        # 对每个数最后start进行异或运算即可
        return [i^(i//2)^start for i in range(2**n)]            