class Solution {
public:
    // 双指针 一个给0 一个给2
    inline void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int>& nums) {
        int index0 = 0;
        int index2 = nums.size()-1;
        int index = 0;
        while(index <= index2){
            if(nums[index] == 0){
                swap(nums[index], nums[index0]);
                index0++;
                if(index < index0){
                    index = index0;
                }
            }
            else if(nums[index] == 2){
                swap(nums[index], nums[index2]);
                index2--;
            }
            else{
                index++;
            }
        }
    }
};