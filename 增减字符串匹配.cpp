class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> ans(n+1, 0);
        int minNum = 0;
        int maxNum = n;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                ans[i] = minNum;
                minNum++;
            }
            else{
                ans[i] = maxNum;
                maxNum--;
            }
        }

        ans[n] = maxNum;

        return ans;
    }
};