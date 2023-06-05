class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()
        n = len(price)
        left, right = 0, price[-1]-price[0]
        while left < right:
            mid = (left+right) // 2
            cnt = 1
            prev = price[0]
            idx = 1
            while idx < n and cnt < k:
                if price[idx]-prev >= mid:
                    prev = price[idx]
                    cnt += 1
                idx += 1

            if cnt < k: # mid下找不到k个
                right = mid
            else: # 能找到k个
                if mid == left:
                    break
                else:
                    left = mid

        if left == right:
            return left
        else:
            mid = right
            cnt = 1
            prev = price[0]
            idx = 1
            while idx < n and cnt < k:
                if price[idx]-prev >= mid:
                    prev = price[idx]
                    cnt += 1
                idx += 1

            if cnt < k: # mid下找不到k个
                return left
            else:
                return right

            