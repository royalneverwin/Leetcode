class Solution {
public:
    static bool Cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Cmp); // 先排序
        int begin = intervals[0][0];
        int end = intervals[0][1];
        int length = intervals.size();
        vector<vector<int>> ans;
        for(int i = 1; i < length; i++){
            if(intervals[i][0] >= begin && intervals[i][0] <= end){ // 能重叠就合并
                begin = min(begin, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
            else{ // 不能重叠就存到数组里, 更新begin, end
                vector<int> tmp = {begin, end};
                ans.push_back(tmp);
                begin = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> tmp = {begin, end};
        ans.push_back(tmp);
        return ans;
    }
};