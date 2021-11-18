//无脑
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n-1);
        string ans = "";
        int count[10] = {0};
        int i = 0;
        for(; i < s.length(); i++){
            if(i == 0)
                count[s[i] - '0']++;
            else if(s[i] == s[i-1])
                count[s[i] - '0']++;
            else{
                char tmp[5];
                sprintf(tmp, "%d", count[s[i-1] - '0']);
                ans.append(tmp);
                ans.append(1, s[i-1]);
                count[s[i-1] - '0'] = 0;
                count[s[i] - '0']++;
            }
        }
        if(count[s[i-1] - '0'] != 0){
            char tmp[5];
            sprintf(tmp, "%d", count[s[i-1] - '0']);
            ans.append(tmp);
            ans.append(1, s[i-1]);
        }
        return ans;
    }
};