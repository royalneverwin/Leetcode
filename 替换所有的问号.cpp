class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '?'){
                if(i == 0){
                    if(s[i+1] == '?'){
                        s[i] = 'a';
                    }
                    else{
                        for(int j = 0; j < 26; j++){
                            if(s[i+1] != 'a' + j){
                                s[i] = 'a' + j;
                                break;
                            }
                        }
                    }
                }
                else if(i == s.length() - 1){
                    for(int j = 0; j < 26; j++){
                        if(s[i-1] != 'a' + j){
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                }
                else{
                    for(int j = 0; j < 26; j++){
                        if(s[i-1] != 'a' + j && s[i+1] != 'a' + j){
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};