class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mmap;
        for(int i = 0; i < list1.size(); i++){
            mmap[list1[i]] = i + 10000;
        }
        for(int j = 0; j < list2.size(); j++){
            if(mmap.count(list2[j])){
                mmap[list2[j]] = mmap[list2[j]] - 10000 + j;
            }
        }
        int minCnt = 9999;
        vector<string> ans;
        for(auto& i: mmap){
            if(i.second < minCnt){
                ans.clear();
                ans.push_back(i.first);
                minCnt = i.second;
            }
            else if(i.second == minCnt)
                ans.push_back(i.first);
        }
        return ans;
    }
};