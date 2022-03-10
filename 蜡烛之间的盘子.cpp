class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // preprocess: find left candle and right candle for index i
        // preprocess: calculate plate's number before index i
        int n = s.length();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        vector<int> plateNum(n, 0);
        vector<int> ans(queries.size(), 0);
        int lastOne = -1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '|')
                lastOne = i;
            leftMax[i] = lastOne;
        }
        lastOne = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '|')
                lastOne = i;
            rightMax[i] = lastOne;
        }
        for(int i = 0; i < n; i++){
            plateNum[i] = cnt;
            if(s[i] == '*')
                cnt++;
        }

        for(int i = 0; i < queries.size(); i++){
            int left = rightMax[queries[i][0]];
            int right = leftMax[queries[i][1]];
            if(left >= right || left == -1 || right == -1)
                ans[i] = 0;
            else
                ans[i] = plateNum[right] - plateNum[left];
        }
        return ans;
    }
};