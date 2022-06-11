class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long minK = 1;
        long maxK = 0;
        for(int i = 0; i < piles.size(); i++) {
            maxK += piles[i];
        }
        while(minK < maxK) {
            long midK = minK + (maxK - minK) / 2;

            long sum = 0;
            for(int i = 0; i < piles.size(); i++) {
                sum += (piles[i] + midK - 1) / midK;
            }
            if(sum <= h) {
                maxK = midK;
            }
            else {
                minK = midK + 1;
            }
        }

        return minK;
    }
};
