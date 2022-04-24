class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.length(), -1);
        int lastIndex = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == c){
                if(lastIndex == -1){
                    for(int j = lastIndex+1; j <= i; j++){
                        ans[j] = i-j;
                    }
                }
                else{
                    for(int j = lastIndex+1; j <= i; j++){
                        ans[j] = min(j-lastIndex, i-j);
                    }
                }
                lastIndex = i;
            }
        }

        if(lastIndex != s.length()-1){
            for(int i = lastIndex+1; i < s.length(); i++){
                ans[i] = i - lastIndex;
            }
        }

        return ans;
    }
};