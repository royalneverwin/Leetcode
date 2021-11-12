//没什么花里胡哨的
class Solution {
public:
    void Exchange(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if(length == 1)
            return;
        if(nums[length-1] > nums[length-2]){
            Exchange(&nums[length-1], &nums[length-2]);
            return;
        }
        int index = length - 1;
        while(index > 0 && nums[index-1] >= nums[index])
            index--;
        if(index == 0){ //降序排列
            sort(nums.begin(), nums.end());
        }
        else{
            int next = 110;
            int nextIndex = 0;
            for(int i = index; i < length; i++)
                if(nums[i] > nums[index-1] && nums[i] < next){
                    next = nums[i];
                    nextIndex = i;
                }
            nums[nextIndex] = nums[index-1];
            nums[index-1] = next;
            sort(nums.begin() + index, nums.end());
        }
    }

};