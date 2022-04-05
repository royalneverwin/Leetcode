class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // 10^6, 20位足够表示 所以最多20个1
        int ans = 0;
        for(int i = left; i <= right; i++){
            int cnt = 0;
            int tmp = i;
            while(tmp > 0){
                cnt += (tmp & 1);
                tmp >>= 1;
            }
            if(cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 || cnt == 13 || cnt == 17 || cnt == 19)
                ans++;
        }
        return ans;
    }
};