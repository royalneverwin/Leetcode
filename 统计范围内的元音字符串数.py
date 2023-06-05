class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = ['a', 'i', 'e', 'o', 'u']
        n = len(words)
        preSum = [0] * n
        cur = 0
        for i in range(n):
            if words[i][0] in vowels and words[i][-1] in vowels:
                cur += 1
            preSum[i] = cur

        m = len(queries)
        res = [0] * m
        for i in range(m):
            if queries[i][0] == 0:
                res[i] = preSum[queries[i][1]]
            else:
                res[i] = preSum[queries[i][1]] - preSum[queries[i][0]-1]

        return res    