class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size() != m * n)
            return ans;
        for(int i = 0; i < m; i++){
            vector<int> tmp(original.begin() + i * n, original.begin() + (i+1) * n);
            ans.push_back(tmp);
        }
        return ans;
    }
};