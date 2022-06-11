class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool> flag(10001, 0);
        for(int i = 0; i < nums.size(); i++){
            if(flag[nums[i]])
                return nums[i];

            flag[nums[i]] = true;
        }

        return 0; // 不会到的

    }
};