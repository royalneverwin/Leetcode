class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        /* Calculate One Subarray */
        int maxSumOfOneSubarray[20010];
        int FirstIndexOfOneArray[20010];
        memset(maxSumOfOneSubarray, 0, sizeof(maxSumOfOneSubarray));
        memset(FirstIndexOfOneArray, 0, sizeof(FirstIndexOfOneArray));
        int length = nums.size();
        int sumOfSubarray = 0; // the sum of Subarray tp calculate maxSumOfOneSubarray
        for(int i = length - k; i < length; i++){
            sumOfSubarray += nums[i];
        }
        maxSumOfOneSubarray[length-k] = sumOfSubarray;
        FirstIndexOfOneArray[length - k] = length - k;
        for(int i = length - k - 1; i >= 2*k; i--){ // we don't need < 2*k info
            sumOfSubarray -= nums[i+k];
            sumOfSubarray += nums[i];
            if(sumOfSubarray >= maxSumOfOneSubarray[i+1]){
                maxSumOfOneSubarray[i] = sumOfSubarray;
                FirstIndexOfOneArray[i] = i;
            }
            else{
                maxSumOfOneSubarray[i] = maxSumOfOneSubarray[i+1];
                FirstIndexOfOneArray[i] = FirstIndexOfOneArray[i+1];
            }
        }
        /* Calculate Two Subarray */
        int maxSumOfTwoSubarray[20010];
        int FirstIndexOfTwoArray[20010];
        memset(maxSumOfTwoSubarray, 0, sizeof(maxSumOfTwoSubarray));
        memset(FirstIndexOfTwoArray, 0, sizeof(FirstIndexOfTwoArray));
        sumOfSubarray = 0;
        for(int i = length - 2*k; i < length - k; i++)
            sumOfSubarray += nums[i];
        maxSumOfTwoSubarray[length - 2*k] = sumOfSubarray + maxSumOfOneSubarray[length - k];
        FirstIndexOfTwoArray[length - 2*k] = length - 2*k;
        for(int i = length - 2*k - 1; i >= k; i--){ // we don't need < k info
            sumOfSubarray -= nums[i+k];
            sumOfSubarray += nums[i];
            if(sumOfSubarray + maxSumOfOneSubarray[i + k] >= maxSumOfTwoSubarray[i+1]){
                maxSumOfTwoSubarray[i] = sumOfSubarray + maxSumOfOneSubarray[i + k];
                FirstIndexOfTwoArray[i] = i;
            }
            else{
                maxSumOfTwoSubarray[i] = maxSumOfTwoSubarray[i+1];
                FirstIndexOfTwoArray[i] = FirstIndexOfTwoArray[i+1];
            }
        }

        /* Calculate Three Subarray */
        sumOfSubarray = 0;
        int maxSumOfThreeSubarray[20010];
        int FirstIndexOfThreeArray[20010];
        memset(maxSumOfThreeSubarray, 0, sizeof(maxSumOfThreeSubarray));
        memset(FirstIndexOfThreeArray, 0, sizeof(FirstIndexOfThreeArray));
        for(int i = length - 3*k; i < length - 2*k; i++)
            sumOfSubarray += nums[i];
        maxSumOfThreeSubarray[length - 3*k] = sumOfSubarray + maxSumOfTwoSubarray[length - 2*k];
        FirstIndexOfThreeArray[length - 3*k] = length - 3*k;
        for(int i = length - 3*k - 1; i >= 0; i--){
            sumOfSubarray -= nums[i+k];
            sumOfSubarray += nums[i];
            if(sumOfSubarray + maxSumOfTwoSubarray[i+k] >= maxSumOfThreeSubarray[i+1]){
                maxSumOfThreeSubarray[i] = sumOfSubarray + maxSumOfTwoSubarray[i+k];
                FirstIndexOfThreeArray[i] = i;
            }
            else{
                maxSumOfThreeSubarray[i] = maxSumOfThreeSubarray[i+1];
                FirstIndexOfThreeArray[i] = FirstIndexOfThreeArray[i+1];
            }
        }
        int index1 = FirstIndexOfThreeArray[0];
        int index2 = FirstIndexOfTwoArray[index1 + k];
        int index3 = FirstIndexOfOneArray[index2 + k];
        vector<int> ans = {index1, index2, index3};
        return ans;
    }
};