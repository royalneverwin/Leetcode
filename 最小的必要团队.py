class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        # 如果遍历people找最少符合人数
        # 要2^60, 肯定超时
        # 所以改成dp
        # 找满足有skill列表为i的people最少人数
        # skill列表通过people更新，这样遍历一次是O(n), 列表长度每次x2也不过O(2n^2)
        rename = {}
        for idx, req_skill in enumerate(req_skills):
            rename[req_skill] = idx

        n = len(people)
        reset = [0 for i in range(n)]
        for i in range(n):
            new_one = 0
            for j in range(len(people[i])):
                new_one |= (1 << (rename[people[i][j]]))
            reset[i] = new_one
        people = reset

        dp = {0: []}
        for i in range(n):
            key_list = list(dp.keys())
            for key in key_list:
                if key|people[i] in dp:
                    if len(dp[key|people[i]]) > len(dp[key])+1:
                        dp[key|people[i]] = dp[key]+[i]
                else:
                    dp[key|people[i]] = dp[key]+[i]
        return dp[(1<<len(req_skills))-1]



