class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int minOne, maxOne;
        for(int i = 0; i < nums.size(); i++){
            minOne = maxOne = nums[i];
            for(int j = i; j < nums.size(); j++){
                if(nums[j] > maxOne)
                    maxOne = nums[j];
                else if(nums[j] < minOne)
                    minOne = nums[j];
                ans += maxOne - minOne;
            }
        }
        return ans;
    }
};

// 单调栈算法
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        // ans = 所有子数组最大值的和 - 所有子数组最小值的和
        int n = nums.size();
        vector<int> minLeft(n, 0);
        vector<int> minRight(n, 0);
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        // 计算nums[i]是最小值和最大值的区间范围
        // 一共 (i - minLeft[i]) * (minRight[i] - i)个子数组nums[i]是最小值
        // 一共 (i - maxLeft[i]) * (maxRight[i] - i)个子数组nums[i]是最大值
        // 因为相邻相同大小的数覆盖的范围没有合并，所以如果nums[i] = nums[j]但i < j,这里也视为nums[i] <* nums[j],
        // 避免会有重合区域

        stack<int> minLeftStack;
        stack<int> minRightStack;
        stack<int> maxLeftStack;
        stack<int> maxRightStack;

        for(int i = 0; i < n; i++){
            int minLeftIndex;
            int maxLeftIndex;

            while(!minLeftStack.empty()){ // 找到比nums[i]小的最近的index
                minLeftIndex = minLeftStack.top();
                if(nums[minLeftIndex] <= nums[i]){
                    minLeft[i] = minLeftIndex;
                    break;
                }
                else
                    minLeftStack.pop();
            }
            if(minLeftStack.empty()){ // 前面没有比nums[i]小的了
                minLeft[i] = -1;
            }

            while(!maxLeftStack.empty()){ // 找到比nums[i]大的最近的index
                maxLeftIndex = maxLeftStack.top();
                if(nums[maxLeftIndex] > nums[i]){
                    maxLeft[i] =maxLeftIndex;
                    break;
                }
                else
                    maxLeftStack.pop();
            }
            if(maxLeftStack.empty()){ // 前面没有比nums[i]大的了
                maxLeft[i] = -1;
            }

            minLeftStack.push(i);
            maxLeftStack.push(i);
        }

        for(int i = n-1; i >= 0; i--){
            int minRightIndex;
            int maxRightIndex;

            while(!minRightStack.empty()){ // 找到比nums[i]小的最近的index
                minRightIndex = minRightStack.top();
                if(nums[minRightIndex] < nums[i]){
                    minRight[i] = minRightIndex;
                    break;
                }
                else
                    minRightStack.pop();
            }
            if(minRightStack.empty()){ // 前面没有比nums[i]小的了
                minRight[i] = n;
            }

            while(!maxRightStack.empty()){ // 找到比nums[i]大的最近的index
                maxRightIndex = maxRightStack.top();
                if(nums[maxRightIndex] >= nums[i]){
                    maxRight[i] =maxRightIndex;
                    break;
                }
                else
                    maxRightStack.pop();
            }
            if(maxRightStack.empty()){ // 前面没有比nums[i]大的了
                maxRight[i] = n;
            }

            minRightStack.push(i);
            maxRightStack.push(i);
        }

        long long maxSum = 0, minSum = 0;
        for(int i = 0; i < n; i++){
            maxSum += (long long)nums[i] * (i - maxLeft[i]) * (maxRight[i] - i);
            minSum += (long long)nums[i] * (i - minLeft[i]) * (minRight[i] - i);
        }
        return maxSum - minSum;
    }
};