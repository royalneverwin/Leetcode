class Solution {
public:
    int maxPow2(int a, int b){ // find x that a / 2^x >= b, make sure a > b
        int ret = 0;
        while(a > b){
            a >>= 1;
            ret++;
        }
        ret--;
        return ret;
    }
    int divide(int dividend, int divisor) {
        int ret = 0;
        //some pre operate, make sure divisor > 0 and dividend > 0
        if(dividend == (1 << 31) && divisor == (1 << 31))
            return 1;
        else if(divisor == (1 << 31)){
            return 0;
        }
        else if(dividend == (1 << 31)){
            if(divisor == 1)
                return dividend;
            else if(divisor == -1)
                return ~(1 << 31);
            else if(divisor > 0){
                dividend += divisor;
                ret++;
            }
            else{ //divisor < 0
                dividend -= divisor;
                ret++;
            }
        }
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return -dividend;
        bool ifMinus = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            ifMinus = true;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        //can't use multply, divide and mod, so the only way is >> and <<
        int maxPow = 0;
        while(dividend > divisor){ //maxPow2 need dividend > divisor, so it should be >, not >=
            maxPow = maxPow2(dividend, divisor);
            ret += pow(2, maxPow);
            dividend -= (divisor << maxPow);
            if(maxPow == 0)
                break;
        }
        while(dividend >= divisor){
            dividend -= divisor;
            ret++;
        }
        if(ifMinus)
            return -ret;
        return ret;
    }
};