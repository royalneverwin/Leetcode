class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int leftHeight = height[0];
        int rightHeight = height[1];
        int maxRightIndex = 1;
        int leftIndex = 0;
        bool flag = false; //剪枝1
        for(int i = 1; i < height.size(); i++){
            cout << leftIndex << ' ' << leftHeight << endl;
            cout << maxRightIndex << ' ' << rightHeight << endl;
            cout << i << ' ' << sum << endl << endl;
            if(height[i] > height[i-1]) //说明有沟，不存在阶梯递减情况
                flag = true;
            //leftIndex和i形成一个沟, 计算这部分的雨水, 
            //更新leftIndex, leftHeight, rightIndex, rightHeight和flag
            if(height[i] >= leftHeight){
                for(int j = leftIndex + 1; j <= i - 1; j++){
                    sum += leftHeight - height[j];
                }
                if(i == height.size() - 1)
                    break;
                leftHeight = height[i];
                leftIndex = i;
                maxRightIndex = leftIndex + 1;
                rightHeight = height[maxRightIndex];
                flag = false;
            }
            else{
                if(rightHeight < height[i]){ //寻找leftIndex右边最大的rightHeight和对应的rightIndex
                    rightHeight = height[i];
                    maxRightIndex = i;
                }
                //leftIndex是最大的, 那么取其右边最大值rightHeight, leftInex和rightIndex中间形成沟
                //计算这部分雨水, 更新leftHeight, leftIndex, 初始化rightHeight, rightIndex, i和flag
                if(i == height.size() - 1 && flag){
                    for(int j = leftIndex + 1; j <= maxRightIndex - 1; j++){
                        sum += rightHeight - height[j];
                    }
                    if(maxRightIndex == i)
                        break;
                    leftHeight = rightHeight;
                    leftIndex = maxRightIndex;
                    rightHeight = height[leftIndex + 1];
                    maxRightIndex = leftIndex + 1;
                    flag = false;
                    i = leftIndex;
                }
            }
        }
        return sum;
    }
};