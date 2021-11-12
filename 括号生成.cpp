//dfs

class Solution {
public:
    vector<string> ans;
    void dfs(int left, string s, int index){
        if(2 * left + index > s.length()){ //剪枝
            return;
        }
        if(left == 0){
            for(int i = 0; i < s.length(); i++){
                if(s[i] != '('){
                    s[i] = ')';
                }
            }
            ans.push_back(s);
            return;
        }
        for(int i = index; i <= s.length() - 2 * left; i++){
            string tmp = s;
            tmp[i] = '(';
            dfs(left-1, tmp, i+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        char ansC[17];
        for(int i = 0; i < 2*n; i++){
            ansC[i] = ' ';
        }
        ansC[2*n] = 0;
        string s = ansC;
        dfs(n, s, 0);
        return ans;
    }
};