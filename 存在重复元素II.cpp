class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // bool flag[2000000001] = {0};
        int length = nums.size();
        int maxj;
        int start = 0;
        int end = min(length - 1, k);
        set<int> numSet;
        for(int i = start; i <= end; i++){
            auto tmp = numSet.insert(nums[i]);
            if(!tmp.second)
                return true;
        }
        while(end != length - 1){
            numSet.erase(nums[start]);
            start++;
            end++;
            auto tmp = numSet.insert(nums[end]);
            if(!tmp.second)
                return true;
        }
        return false;
    }
};