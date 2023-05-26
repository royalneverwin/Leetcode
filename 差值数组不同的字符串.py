class Solution:
    def oddString(self, words: List[str]) -> str:
        n = len(words)
        difference = []
        for i in range(n):
            difference.append([])
            for j in range(len(words[i])-1):
                difference[i].append(ord(words[i][j+1])-ord(words[i][j]))

        cnt = defaultdict(list)
        for i in range(n):
            difference[i] = tuple(difference[i])
            cnt[difference[i]].append(words[i])

        for key, val in cnt.items():
            if len(val) == 1:
                return val[0]

