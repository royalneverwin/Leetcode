class Solution {
public:
    // 第45个已经超过了10^9
    int findMinFibonacciNumbers(int k) {
        long F[45];
        F[1] = 1;
        F[2] = 1;
        for(int i = 3; i < 45; i++){
            F[i] = F[i-1] + F[i - 2];
        }
        int index = 44;
        int cnt = 0;
        while(k > 0){
            while(k < F[index])
                index--;
            k = k - F[index];
            cnt++;
        }
        return cnt;
    }
};