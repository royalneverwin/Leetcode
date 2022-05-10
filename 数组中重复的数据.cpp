class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){ // 0表示空缺 -1表示出现两次 i+1表示出现一次
            if(nums[i] == i+1 || nums[i] == 0 || nums[i] == -1)
                continue;
            else{
                int cur = nums[i];
                int next;
                nums[i] = 0;
                while(nums[cur-1] != cur && nums[cur-1] != 0 && nums[cur-1] != -1){
                    next = nums[cur-1];
                    nums[cur-1] = cur;
                    cur = next;
                }

                if(nums[cur-1] == cur)
                    nums[cur-1] = -1;
                else if(nums[cur-1] == 0)
                    nums[cur-1] = cur;

            }
        }

        int index = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == -1){
                nums[index] = i+1;
                index++;
            }

        nums.erase(nums.begin() + index, nums.end());
        return nums;
    }
};