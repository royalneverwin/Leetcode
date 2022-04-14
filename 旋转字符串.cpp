class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == goal[0]){
                int cnt = 0;
                bool flag = true;
                for(int j = 1; j < s.length(); j++){
                    if(s[(i+j) % s.length()] != goal[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    return true;
            }
        }
        return false;
    }
};