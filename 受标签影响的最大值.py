class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        n = len(values)
        idxes = [i for i in range(n)]
        idxes.sort(key=lambda x: values[x], reverse=True)

        cnt = defaultdict(int)
        res = 0
        idx = 0
        for i in range(numWanted):
            while i+idx < n and cnt[labels[idxes[i+idx]]] >= useLimit:
                idx += 1

            if i+idx == n:
                break
            res += values[idxes[i+idx]]
            cnt[labels[idxes[i+idx]]] += 1
        return res