class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> prev = heights;
        sort(heights.begin(), heights.end());
        int ans = 0;
        for(size_t i = 0; i < heights.size(); i++) {
            if(prev[i] != heights[i])
                ans++;
        }

        return ans;
    }
};