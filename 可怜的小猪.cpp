class Solution {
public:
    //只有x头猪，一次机会，最多可以检测2^x个buckets
    //只有x头猪，y次机会，最多可以检测(y+1)^x个buckets
    //只有四桶，一次机会，两头猪即可
    //只有两桶，一次机会，一头猪即可
    //只有一桶，一次机会，一头猪即可
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1) //不需要检查
            return 0;
        int time = minutesToTest / minutesToDie;
        for(int i = 1; i <= 10; i++){
            if((int)pow(time + 1, i) >= buckets)
                return i;
        }
        return -1;
    }
};

//建议看看官方的动态规划，那才是标准解法