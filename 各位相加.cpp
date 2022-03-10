class Solution {
public:
    int addDigits(int num) {
        int n = num;
        int sum = 0;
        while(n >= 10){
            while(n > 0){
                sum += n % 10;
                n /= 10;
            }
            n = sum;
            sum = 0;
        }
        return n;
    }
};