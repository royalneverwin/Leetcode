class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n & 1; // 0表示0，1表示1
        n >>= 1;
        while(n > 0){
            if(flag && !(n&1)){
                flag = false;
                n >>= 1;
            }
            else if(!flag && (n&1)){
                flag = true;
                n >>= 1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};