class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        int length = nums.size();
        bool flag = true;
        while(flag){
            flag = false;
            int index = length - 1;
            for(index = length - 1; index >= 1; index--){
                // 找到第一个nums[index] > nums[index-1]
                if(nums[index] > nums[index-1]){
                    int replaceIndex = -1;
                    for(int i = length - 1; i >= index; i--){
                        if(nums[i] > nums[index-1]){
                            if(replaceIndex == -1)
                                replaceIndex = i;
                            else if(nums[replaceIndex] > nums[i])
                                replaceIndex = i;
                        }
                    }
                    int tmp = nums[index-1];
                    nums[index-1] = nums[replaceIndex];
                    nums[replaceIndex] = tmp;
                    sort(nums.begin() + index, nums.end());
                    flag = true;
                    break;
                }
            }
            if(!flag){ // 从大到小排列, 退出
                break;
            }
            else{
                ans.push_back(nums);
            }
        }
        return ans;
    }
};