class Solution {
public:
    int lastRemaining(int n) {
        vector<bool> op(31); // 0表示div, 1表示2n-1 -> n
        int index = 0;
        while(n != 1){
            // 从左到右
            n /= 2;
            op[index] = false;
            index++;
            if(n == 1)
                break;
            else if(n % 2 == 0)
                op[index] = true;
            else
                op[index] = false;
            index++;
            n /= 2;
        }
        for(int i = index - 1; i >= 0; i--){
            if(op[i])
                n = 2*n - 1;
            else
                n = 2*n;
        }
        return n;
    }
};