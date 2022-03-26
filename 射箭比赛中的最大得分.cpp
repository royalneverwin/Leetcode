class Solution {
public:
    void dfs(int leftArrows, vector<int>& aliceArrows, int k, int score, vector<int>& ans, vector<int> tmp, int& maxScore){
        if(k == 12){
            if(score > maxScore){
                if(leftArrows != 0){
                    tmp[0] += leftArrows;
                }
                ans = tmp;
                maxScore = score;
            }
            return;
        }
        dfs(leftArrows, aliceArrows, k+1, score, ans, tmp, maxScore);
        if(leftArrows > aliceArrows[k]){
            leftArrows -= (aliceArrows[k] + 1);
            score += k;
            tmp[k] = aliceArrows[k] + 1;
            dfs(leftArrows, aliceArrows, k+1, score, ans, tmp, maxScore);
        }

    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        // 就2^12种可能，枚举就行
        vector<int> ans(12, 0);
        vector<int> tmp(12, 0);
        int maxScore = 0;
        dfs(numArrows, aliceArrows, 0, 0, ans, tmp, maxScore);
        return ans;
    }
};