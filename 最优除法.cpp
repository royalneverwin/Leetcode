class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        //  简单的数学 肯定是num0 / (num1 / num2 / ...) 最大
        string ans = to_string(nums[0]);
        if(nums.size() > 1){
            ans += '/';
            if(nums.size() > 2){
                ans += '(';
                ans += to_string(nums[1]);
                for(int i = 2; i < nums.size(); i++){
                    ans += '/';
                    ans += to_string(nums[i]);
                }
                ans += ')';

            }
            else
                ans += to_string(nums[1]);
        }
        return ans;
    }
};