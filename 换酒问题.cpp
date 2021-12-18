class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        // remember, bottles can't exchange in one round won't be thrown away, should be stored
        int left = 0;
        while(numBottles + left >= numExchange){
            int tmp  = (numBottles + left) /  numExchange;
            left = (numBottles + left) % numExchange;
            numBottles = tmp;
            ans += numBottles;
        }
        return ans;
    }
};