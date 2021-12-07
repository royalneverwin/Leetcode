class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        medal = ('Gold Medal', 'Silver Medal', 'Bronze Medal');
        ans = [""] * len(score);
        arr = sorted(enumerate(score), key=lambda x: x[1], reverse=True);
        for i, (index, _) in enumerate(arr): # arr is a list of tuple
            ans[index] = medal[i] if(i < 3) else str(i+1);
        return ans;
