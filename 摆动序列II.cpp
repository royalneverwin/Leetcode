class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 1)
            return;
        sort(nums.begin(), nums.end());
        vector<int> tmp = nums;

        int index;
        if(nums.size() % 2 == 0)
            index = nums.size()-2;
        else
            index = nums.size()-1;
        for(int i = 0; i < tmp.size(); i++) {
            nums[index] = tmp[i];
            index -= 2;
            if(index < 0) {
                if(nums.size() % 2 == 0)
                    index = nums.size()-1;
                else
                    index = nums.size()-2;
            }
        }
    }
};