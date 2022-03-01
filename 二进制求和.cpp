class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.length()-1, ib = b.length()-1;
        int length = max(a.length(), b.length());
        string ans(length+1, ' ');
        int flag = 0;
        int index = length;
        while(ia >= 0 && ib >= 0){
            char next = a[ia] + b[ib] - '0' + flag;
            flag = 0;
            if(next >= '2'){ // 要进位
                flag = 1;
                next -= 2;
            }
            ans[index] = next;
            ia--;
            ib--;
            index--;
        }

        while(ia >= 0){
            char next = a[ia] + flag;
            flag = 0;
            if(next == '2'){
                flag = 1;
                next = '0';
            }
            ans[index] = next;
            ia--;
            index--;
        }

        while(ib >= 0){
            char next = b[ib] + flag;
            flag = 0;
            if(next == '2'){
                flag = 1;
                next = '0';
            }
            ans[index] = next;
            ib--;
            index--;
        }

        if(flag){
            ans[0] = '1';
            return ans;
        }
        return ans.substr(1, length);
    }
};