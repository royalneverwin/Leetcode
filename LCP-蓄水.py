class Solution:
    def storeWater(self, bucket: List[int], vat: List[int]) -> int:
        # 贪心
        res = 0
        n = len(bucket)
        cnt = [0] * n
        for i in range(n):
            if bucket[i] == 0 and vat[i] > 0:
                bucket[i] = 1
                res += 1
            if vat[i] > 0:
                cnt[i] = (vat[i] + bucket[i] - 1) // bucket[i]

        first_max = max(cnt)
        # 最多加max_one-1次，而且每次肯定加的是cnt最大的那个
        for i in range(1, first_max):
            max_one = max(cnt)
            max_idx = cnt.index(max_one)
            bucket[max_idx] += 1
            cnt[max_idx] = (vat[max_idx] + bucket[max_idx] - 1) // bucket[max_idx]
            first_max = min(first_max, max(cnt)+i)

        return res+first_max







