class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> mmap;
        unordered_map<int, int> tmp;
        for(int i = 0; i < nums.size(); i++){ // dp
            tmp = mmap;
            if(!tmp.count(nums[i])){
                tmp[nums[i]] = 1;
            }
            else{
                tmp[nums[i]]++;
            }
            for(auto& j: mmap){
                if(!tmp.count(j.first | nums[i])){
                    tmp[j.first | nums[i]] = j.second;
                }
                else{
                    tmp[j.first | nums[i]] += j.second;
                }
            }
            mmap = tmp;
        }
        int ans = 0;
        int maxOne = -1;
        for(auto& i: mmap){
            if(i.first > maxOne){
                ans = i.second;
                maxOne = i.first;
            }
        }
        return ans;
    }
};