class Solution {
public:
    // 二分
    int mySqrt(int x) {
        long left = 0;
        long right = x;
        long middle = (left + right) / 2;
        while(left+1 < right){
            if(middle * middle < static_cast<long>(x)){
                left = middle;
                middle = (left + right) / 2;
            }
            else if(middle * middle > static_cast<long>(x)){
                right = middle-1;
                middle = (left + right) / 2;
            }
            else{
                return middle;
            }
        }
        if(left == right){
            return left;
        }
        else if(right * right <= static_cast<long>(x)){
            return right;

        }
        else{
            return left;
        }
    }
};

class Solution {
public:
    int mySqrt(int x) {
        // 数学方法
        // x^0.5 = (e^lnx)^0.5 = e^(0.5lnx)
        // 这样不用指数函数, 而是用exp函数
        // 注意小数会有误差 所以要多加一个判断
        if(x == 0)
            return 0;
        int ans = exp(0.5 * log(x)) + 1;
        return (long)ans * ans > x? ans-1: ans;
    }
};