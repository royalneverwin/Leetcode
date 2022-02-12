class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            if(umap.find(nums[i]) == umap.end())
                umap[nums[i]] = 1;
            else
                umap[nums[i]]++;
        }
        int ans = 0;
        for(auto i = umap.begin(); i != umap.end(); i++){
            if(i->second == 1)
                ans += i->first;
        }
        return ans;
    }
};


class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> flag(101, 0);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!flag[nums[i]]){
                ans += nums[i];
                flag[nums[i]] = 1;
            }
            else if(flag[nums[i]] == 1){
                ans -= nums[i];
                flag[nums[i]] = 2;
            }
        }
        return ans;
    }
};