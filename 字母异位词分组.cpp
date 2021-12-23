class Solution {
public:
    // 用int数的26位代表26个字母，比较int数是否一样就可以知道是不是一个组合
    // 不太行啊, 一个字母不仅出现一次, 寄
    // 正常方法吧 计数或者排序
    // 我选择排序，方便
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mmap;
        vector<vector<string>> ans;
        int cnt = 0;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(mmap.find(tmp) != mmap.end()) // 匹配到了
                ans[mmap[tmp]].push_back(strs[i]);
            else{ // 没有匹配到
                mmap[tmp] = cnt;
                vector<string> empty = {strs[i]};
                ans.push_back(empty);
                cnt++;
            }
        }
        return ans;
    }
};