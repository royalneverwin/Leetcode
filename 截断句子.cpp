class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                cnt++;
                if(cnt == k){
                    return s.substr(0, i);
                }
            }
        }
        return s;
    }
};