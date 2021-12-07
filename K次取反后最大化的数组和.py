class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        numsCnt = Counter(nums);
        total = sum(nums);

        for i in range(-100, 0): # change minus first
            if numsCnt[i]:
                cnt = min(k, numsCnt[i]);
                total += -i * 2 * cnt;
                k -= cnt;
                numsCnt[i] -= cnt;
                numsCnt[-i] += cnt; # prepare to find min when all minus are turned
                if k == 0:
                    return total;
        if not numsCnt[0] and k % 2 != 0:
            for i in range(1, 101):
                if numsCnt[i]:
                    total -= i * 2;
                    return total;

        return total;
