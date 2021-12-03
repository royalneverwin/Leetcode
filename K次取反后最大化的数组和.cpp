class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minusCnt = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)
                minusCnt++;
            sum += nums[i];
        }
        for(int i = 0; i < min(k, minusCnt); i++){ // 先把负的变成正的
            nums[i] = -nums[i];
            sum += 2 * nums[i];
        }
        if(k > minusCnt){ //负的变成正的还没完
            k -= minusCnt;
            sort(nums.begin(), nums.end());
            if(k % 2 == 0) //最终不变
                return sum;
            else //把最小的变成负的
                return sum - 2 * nums[0];
        }
        else
            return sum;

    }
};