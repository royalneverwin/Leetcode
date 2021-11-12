// STL find秒了... 标答是二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto i = find(nums.begin(), nums.end(), target);
        if(i == nums.end())
            return -1;
        else{
            return i - nums.begin();
        }
    }
};