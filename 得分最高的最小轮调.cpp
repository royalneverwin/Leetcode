class Solution {
public:
    int bestRotation(vector<int>& nums) {
        // 正常情况都是O(n^2)的时间复杂度
        // 所以不能用正常数组记录得分, 要用差分数组diff[i] = k[i] - k[i-1]
        int n = nums.size();
        vector<int> diff(n, 0);
        // preprocess
        for(int i = 0; i < n-1; i++){
            if(nums[i] > i){ // 如果nums[i]的k范围在中间
                int low = i + 1;
                int high = i + n - nums[i] + 1;
                if(high == n){
                    diff[low]++;
                }
                else{
                    diff[low]++;
                    diff[high]--;
                }
            }
            else if(nums[i] <= i){ // 如果nums[i]的k范围是两边
                int low = i + 1;
                int high = i - nums[i] + 1;
                diff[0]++;
                diff[high]--;
                diff[low]++;
            }
        }
        if(nums[n-1] <= n-1){ // 对第n-1个特殊处理
            diff[0]++;
            int high = n-1-nums[n-1]+1;
            if(high != n)
                diff[n-1-nums[n-1]+1]--;
        }

        // 前缀和
        int ans = 0;
        int maxOne = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += diff[i];
            if(sum > maxOne){
                maxOne = sum;
                ans = i;
            }
        }
        return ans;
    }
};