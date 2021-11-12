//stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                bracket.push(s[i]);
            }
            else if(s[i] == ')'){
                if(bracket.empty() || bracket.top() != '('){
                    return false;
                }
                else{
                    bracket.pop();
                }
            }
            else if(s[i] == '['){
                bracket.push(s[i]);
            }
            else if(s[i] == ']'){
                if(bracket.empty() || bracket.top() != '['){
                    return false;
                }
                else{
                    bracket.pop();
                }
            }
            else if(s[i] == '{'){
                bracket.push(s[i]);
            }
            else if(s[i] == '}'){
                if(bracket.empty() || bracket.top() != '{'){
                    return false;
                }
                else{
                    bracket.pop();
                }
            }
        }
        if(!bracket.empty()){
            return false;
        }
        return true;
    }
};