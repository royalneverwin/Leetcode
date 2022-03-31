class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int length = nums.size();
        int oldErase = 0;
        int newErase = 0;
        for(int i = 0; i < nums.size(); i++){
            if((i-oldErase) % 2 == 0){
                newErase = 0;
                while(i+1+newErase < length && nums[i] == nums[i+1+newErase]){ // 需要处理
                    newErase++;
                }
                oldErase += newErase;
                i = i+newErase;
            }
        }
        if((length - oldErase) % 2 != 0)
            oldErase++;
        return oldErase;
    }
};