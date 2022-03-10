class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        int n = abs(num);
        while(n >= 7){
            ans += '0' + n % 7;
            n /= 7;
        }
        ans += '0' + n;
        if(num < 0)
            ans += '-';
        return string(ans.rbegin(), ans.rend());
    }
};