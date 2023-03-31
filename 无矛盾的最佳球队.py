class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        people = [(s, a) for s, a in zip(scores, ages)]
        people = [(i, s, a) for i, (s, a) in enumerate(people)] # idx, score, age
        def cmp(p1, p2):
            if p1[2] < p2[2]:
                return -1
            elif p1[2] > p2[2]:
                return 1
            else:
                if p1[1] < p2[1]:
                    return -1
                elif p1[1] > p2[1]:
                    return 1
                else:
                    return 0
        people.sort(key=functools.cmp_to_key(cmp)) # 根据ages排序,age相同按照score排序

        # 相当于在people中找到最大升序子序列
        n = len(people)
        dp = [people[i][1] for i in range(n)]
        for i in range(1, n):
            max_prev = 0
            for j in range(i):
                if people[j][2] == people[i][2]:
                    max_prev = max(max_prev, dp[j])
                elif people[j][1] <= people[i][1]:
                    max_prev = max(max_prev, dp[j])
            dp[i] += max_prev

        return max(dp)