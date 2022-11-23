class Solution:
    def soupServings(self, n: int) -> float:
        # 笑死 tnnd
        # 超时怎么办呢
        # 因为 > 几k之后A先分配完的概率无限趋近于1 所以直接n大的时候不用算直接返回1就行 我日你的哥
        if n > 4800:
            return 1.0

        if n > 4275:
            return 0.99999

        if n % 25:
            n = ((n // 25) + 1) * 25

        my_dict_A = {}
        my_dict_AB = {}
        # initial
        my_dict_AB[(0, 0)] = 1
        my_dict_A[(0, 0)] = 0
        for i in range(25, n+25, 25):
            my_dict_A[(0, i)] = 1
            my_dict_AB[(0, i)] = 0
            my_dict_A[(i, 0)] = 0
            my_dict_AB[(i, 0)] = 0

        dis = ((100, 0), (75, 25), (50, 50), (25, 75))

        for i in range(25, n+25, 25):
            for j in range(25, n+25, 25):
                p_a, p_ab = 0, 0
                for d in dis:
                    tmpa, tmpb = max(i - d[0], 0), max(j - d[1], 0)
                    p_a += 0.25 * my_dict_A[(tmpa, tmpb)]
                    p_ab += 0.25 * my_dict_AB[(tmpa, tmpb)]
                my_dict_A[(i, j)] = p_a
                my_dict_AB[(i, j)] = p_ab


        return my_dict_A[(n, n)] + 0.5 * my_dict_AB[(n, n)]



