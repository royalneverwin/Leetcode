class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        n = len(reward1)
        subs = [0] * n
        for i in range(n):
            subs[i] = reward1[i]-reward2[i]

        subs.sort(reverse=True)
        res = sum(reward2)
        for i in range(k):
            res += subs[i]

        return res