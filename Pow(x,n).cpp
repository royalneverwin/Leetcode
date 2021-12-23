class Solution {
public:
    double myPow(double x, int n) {
        // preprocess
        if(x == 0 && n <= 0)
            return (1 << 31);
        else if(x == 0)
            return 0;
        else if(n == 0)
            return 1;

        double left = 1;
        bool flag = false;

        // judge if n < 0
        if(n < 0){
            flag = true;
            n = abs(n);
        }

        // faster calculate
        while(n > 1){
            if(n % 2 != 0)
                left *= x;
            x = x * x;
            n = n / 2;
        }
        x = x * left;

        // return 
        if(flag)
            return 1 / x;
        return x;
    }
};