//双指针法

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int left = 0;
        int right = length - 1;
        int ans = 0;
        while(left < right){ //找哪一边小，长的边不用缩，缩了面积肯定更小
            if(height[left] < height[right]){
                ans = max(ans, height[left] * (right - left));
                int index = left;
                while(index < right && height[index] <= height[right]){
                    if((right - index) * min(height[index], height[right]) > ans){
                        break;
                    }
                    index++;
                }
                if(index == right){
                    break;
                }
                else{
                    left = index;
                }
            }
            else{
                ans = max(ans, height[right] * (right - left));
                int index = right;
                while(index > left && height[index] <= height[left]){
                    if((index - left) * min(height[index], height[left]) > ans){
                        right = index;
                        break;
                    }
                    index--;
                }
                if(index == left){
                    break;
                }
                else{
                    right = index;
                }
            }
        }
        return ans;
    }
};