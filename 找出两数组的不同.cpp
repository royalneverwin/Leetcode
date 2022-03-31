class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> fornum1; // second用来判断是否只在nums1中
        unordered_set<int> fornum2; // 用来判断nums2中的独有元素是否已被添加到ans2中
        for(int i = 0; i < nums1.size(); i++){
            fornum1[nums1[i]] = 1;
        }
        vector<int> ans1;
        vector<int> ans2;
        vector<vector<int>> ans(2, vector<int>(0,0));
        for(int i = 0; i < nums2.size(); i++){
            if(!fornum1.count(nums2[i]) && !fornum2.count(nums2[i])){
                ans2.emplace_back(nums2[i]);
                fornum2.insert(nums2[i]);
            }

            else{
                fornum1[nums2[i]] = 0;
            }
        }
        for(auto& i: fornum1){
            if(i.second)
                ans1.emplace_back(i.first);
        }
        ans[0] = ans1;
        ans[1] = ans2;
        return ans;
    }
};