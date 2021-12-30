class Solution {
public:
    // 枚举
    int countQuadruplets(vector<int>& nums) {
        int length = nums.size();
        int ans = 0;
        for(int i = 0; i < length - 3; i++){
            for(int j = i + 1; j < length - 2; j++){
                for(int k = j + 1; k < length - 1; k++){
                    for(int l = k + 1; l < length; l++){
                        if(nums[i] + nums[j] + nums[k] == nums[l])
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        // 用hash表存nums[d] - nums[c]
        // 倒序遍历b和a, 这样只要不断往hash表中加nums[d] - nums[c]即可
        int length = nums.size();
        int ans = 0;
        map<int, int> mmap;
        for(int b = length - 3; b >= 1; b--){
            for(int d = b + 2; d < length; d++){ // 对不同的b更新mmap
                if(mmap.find(nums[d] - nums[b+1]) == mmap.end())
                    mmap[nums[d] - nums[b+1]] = 1;
                else
                    mmap[nums[d] - nums[b+1]]++;
            }
            for(int a = b - 1; a >= 0; a--){ // 遍历
                if(mmap.find(nums[a] + nums[b]) != mmap.end())
                    ans += mmap[nums[a] + nums[b]];
            }
        }
        return ans;
    }
};