class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        dp = [1e7 for i in range(n+1)]
        dp[-1] = 0
        for i in range(0, n):
            cur_max = books[i][1]
            cur_wid = books[i][0]
            dp[i] = min(dp[i], cur_max+dp[i-1])
            for j in range(i-1, -1, -1):
                if books[j][0]+cur_wid <= shelfWidth:
                    cur_wid += books[j][0]
                    cur_max = max(cur_max, books[j][1])
                    dp[i] = min(dp[i], cur_max+dp[j-1])
                else:
                    break

        return dp[n-1]


