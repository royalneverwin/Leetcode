class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        queries = [(i, j) for i, j in enumerate(queries)]
        queries.sort(key=lambda x:x[1])

        n = len(nums)
        m = len(queries)
        answer = [0 for i in range(m)]
        idx = 0
        cur_sum = 0
        for i in range(m):
            while True:
                if idx == n:
                    break
                if cur_sum + nums[idx] <= queries[i][1]:
                    cur_sum += nums[idx]
                    idx += 1
                else:
                    break
            answer[queries[i][0]] = idx

        return answer
            