class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1)
            return 9;
        long maxLeft = (long)pow(10, n) - 1;
        for(; maxLeft >= (long)pow(10, n-1); maxLeft--){ // 枚举左半部分即可 且默认2n
            long complete = maxLeft;
            long curLeft = maxLeft;
            while(curLeft > 0){
                complete = complete * 10 + curLeft % 10;
                curLeft /= 10;
            }
            for(long x = (long)pow(10, n)-1; x >= sqrt(complete); x--){
                if(complete % x == 0) // 也是n位 能整除
                    return complete % 1337;
            }
        }
        cout << "There is some ans that not in 2n length" << endl;
        return -1;

    }
};