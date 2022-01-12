class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        bool flag = true;
        int length = intervals.size();
        for(int i = 0; i < length; i++){ // 直接遍历, 已经排过序了
            if(intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else if(intervals[i][0] > newInterval[1]){
                if(flag){
                    vector<int> tmp = {start, end};
                    ans.push_back(tmp);
                    flag = false;
                }
                ans.push_back(intervals[i]);
            }
            else{
                start = min(start, intervals[i][0]);
                end = max(intervals[i][1], end);
            }
        }
        if(flag){
            vector<int> tmp = {start, end};
            ans.push_back(tmp);
            flag = false;
        }
        return ans;
    }
};