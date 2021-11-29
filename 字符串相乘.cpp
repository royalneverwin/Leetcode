class Solution {
public:

    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string ans(len1 + len2, '0');
        int flag = 0;
        int n1, n2, nn, na;
        for(int i = len1 - 1; i >= 0; i--){
            int j;
            for(j = len2 - 1; j >= 0; j--){
                n1 = num1[i] - '0'; //num2
                n2 = num2[j] - '0'; //num1
                na = ans[i + j + 1] - '0'; //ans
                nn = n1 * n2 + na + flag;
                ans[i + j + 1] = nn % 10 + '0';
                flag = nn / 10;
            }
            int index = i + j + 1;
            while(flag > 0){
                na = ans[index] - '0';
                nn = na + flag;
                ans[index] = nn % 10 + '0';
                flag = nn / 10;
                index--;
            }
        }
        auto i = ans.begin();
        while(*i == '0' && i + 1 != ans.end()){
            ans.erase(i);
            i = ans.begin();
        }
        return ans;
    }
};