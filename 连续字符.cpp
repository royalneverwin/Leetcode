class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int length = 1;
        char prev = s[0];
        for(int i = 1; i < s.length(); i++){
            if(s[i] == prev)
                length++;
            else{
                ans = max(ans, length);
                if(s.length() - i <= ans)
                    break;
                length = 1;
                prev = s[i];
            }
        }
        ans = max(ans, length);
        return ans;
    }
};