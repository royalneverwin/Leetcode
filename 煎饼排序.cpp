class Solution {
public:
    void Count(vector<int>& ans, vector<int>& arr, int length){
        if(length == 1)
            return;
        else if(arr[length-1] == length) // 最大的已经在最后 不用找了
            Count(ans, arr, length-1);
        else{
            int maxNum = 0;
            int maxIndex = 0;
            // 找到最大的
            for(int i = 0; i < length; i++){
                if(arr[i] > maxNum){
                    maxNum = arr[i];
                    maxIndex = i;
                }
            }
            ans.push_back(maxIndex + 1);
            ans.push_back(length);
            reverse(arr.begin(), arr.begin() + maxIndex + 1);
            reverse(arr.begin(), arr.begin() + length);
            Count(ans, arr, length-1);
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        // 先把最大的煎饼排序到第一个，再煎饼排序到最后一个
        vector<int> ans;
        Count(ans, arr, arr.size());
        return ans;
    }
};