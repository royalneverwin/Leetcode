//无脑
class Solution {
public:
    bool ifUpper(char c){
        if(c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        bool ifShouldAllUpper = false;
        if(word.length() == 1)
            return true;
        if(!ifUpper(word[0]))
            ifShouldAllUpper = false;
        else if(ifUpper(word[0]) && !ifUpper(word[1]))
            ifShouldAllUpper = false;
        else if(ifUpper(word[0]) && ifUpper(word[1]))
            ifShouldAllUpper = true;
        for(int i = 1; i < word.length(); i++){
            if(ifUpper(word[i]) && !ifShouldAllUpper){
                return false;
            }
            if(!ifUpper(word[i]) && ifShouldAllUpper){
                return false;
            }
        }
        return true;
    }
};