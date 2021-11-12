//最优解法： 遍历 + 双指针法遍历O(n^2)
//我的解法：遍历 + 遍历 + 二分查找O(n^2logn)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) //这里要特判，因为下面nums.size() - 2返回值是unsigned int
            return ans;
        sort(nums.begin(), nums.end());
        int three = 100010;
        int previ = 100010;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0){ //大于0肯定不可能了后面
                break;
            }
            if(i != 0 && nums[i] == previ){
                continue;
            }
            else{
                previ = nums[i];
                int prevj = 100010;
                for(int j = i+1; j < nums.size()-1; j++){
                    if(j != i+1 && nums[j] == prevj){
                        continue;
                    }
                    else{
                        prevj = nums[j];
                        three = 0 - nums[i] - nums[j];
                        //注意应该用binary_search, 我们已经提前排序了
                        if(binary_search(nums.begin() + j + 1, nums.end(), three)){
                            vector<int> tmp;
                            tmp.push_back(nums[i]);
                            tmp.push_back(nums[j]);
                            tmp.push_back(three);
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};