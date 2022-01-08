class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int tmp = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                tmp++;
                ans = max(ans, tmp);
            }
            else if(s[i] == ')')
                tmp--;
        }
        return ans;
    }
};