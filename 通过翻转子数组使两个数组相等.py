class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        cnt1 = [0 for i in range(1001)]
        cnt2 = [0 for i in range(1001)]
        for i in target:
            cnt1[i] += 1
        for i in arr:
            cnt2[i] += 1

        for i, j in zip(cnt1, cnt2):
            if i != j:
                return False

        return True