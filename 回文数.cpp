class Solution {
public:
    bool isPalindrome(int x) { //我们把这个数倒过来如果也对那么就是回文数
        if(x < 0)
            return false;
        int prev = x;
        int reverse = 0;
        while(x){
            if(reverse > (~(1 << 31)) / 10)
                return false;
            reverse *= 10;
            if(reverse > (~(1 << 31)) - x % 10)
                return false;
            reverse += x % 10;
            x /= 10;
        }
        if(reverse == prev)
            return true;
        else
            return false;
    }
};