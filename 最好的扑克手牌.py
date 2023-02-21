class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return "Flush"
        cnt = [0 for i in range(13)]
        for rank in ranks:
            cnt[rank-1] += 1

        val = max(cnt)
        if val >= 3:
            return "Three of a Kind"
        elif val == 2:
            return "Pair"
        else:
            return "High Card"


