class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size()-1;


        while(left < right){
            while(left < right && nums[left] % 2 == 0)
                left++;
            while(left < right && nums[right] % 2 != 0)
                right--;

            if(left < right){
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;
                left++;
                right--;
            }
        }

        return nums;
    }
};