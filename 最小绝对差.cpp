class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dis = arr[1] - arr[0];
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>{arr[0], arr[1]});
        for(int i = 2; i < arr.size(); i++)
            if(arr[i] - arr[i-1] < dis) {
                ans.clear();
                ans.emplace_back(vector<int>{arr[i-1], arr[i]});
                dis = arr[i] - arr[i-1];
            }
            else if(arr[i] - arr[i-1] == dis) {
                ans.emplace_back(vector<int>{arr[i-1], arr[i]});
            }
        return ans;
    }
};