class Solution {
public:
    // O(n)的时间复杂度：遍历一次nums, 对>=1且<=nums.size()的数a, 记录另一个bool数组的index = a为true
    // 第二次遍历bool数组, 找到第一个false的index即为最小正整数 
    // 但很显然这不属于常数级别额外空间方法, 因此, 我们要对nums数组本身进行修改
    // 把符合上述条件的a放到对应的index处, 第二次遍历nums, 第一个index != nums[index]的index就是ans
    void Shuffle(vector<int>& nums, int num){ // move num to where it belongs to
        if(nums[num - 1] == num) // a shuffle round is done
            return;
        int tmp = nums[num - 1];
        nums[num - 1] = num;
        if(tmp > 0 && tmp <= nums.size()){ // throw away
            Shuffle(nums, tmp);
        }
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0 || nums[i] > nums.size()){ // don't need to operate
                continue;
            }
            else if(nums[i] == i + 1){ // already lie where it belongs to
                continue;
            }
            else{
                Shuffle(nums, nums[i]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};