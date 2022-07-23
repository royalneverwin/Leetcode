class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> umap;
        vector<int> cnt(n, 0);
        for(auto& l: sequences) {
            for(int i = 1; i < l.size(); i++) {
                if(!umap[l[i-1]].count(l[i])) {
                    umap[l[i-1]].insert(l[i]);
                    cnt[l[i]-1]++;
                }
            }
        }
        vector<int> ret(n, 0);
        int num = 0;
        for(int i = 0; i < n; i++) {
            if(cnt[i] == 0) {
                if(num == 0)
                    num = i+1;
                else
                    return false;
            }
        }
        int nxt = 0;
        int idx = 0;
        if(nums[idx] != num)
            return false;
        idx++;
        while(idx < n) {
            for(auto& i: umap[num]) {
                cnt[i-1]--;
                if(cnt[i-1] == 0) {
                    if(nxt == 0) {
                        nxt = i;
                    }
                    else {
                        return false;
                    }
                }
            }
            num = nxt;
            nxt = 0;
            if(nums[idx] != num)
                return false;
            idx++;
        }
        return true;
    }
};