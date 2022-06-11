class Solution {
public:
    // 有序集合
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();

        vector<int> ans(n, 0);

        map<int, int> heights; // 从first开始的点高度都为second
        heights[0] = 0;
        for(int i = 0; i < positions.size(); i++) {
            int left = positions[i][0];
            int right = positions[i][0] + positions[i][1];
            auto lt = heights.upper_bound(left);
            auto rt = heights.lower_bound(right);

            rt--;
            int rightH = rt->second;
            rt++;

            lt--;
            int maxH = 0;
            for(auto p = lt; p != rt; p++) {
                maxH = max(maxH, p->second + positions[i][1]);
            }
            lt++;

            if(lt != heights.end())
                heights.erase(lt, rt);
            heights[left] = maxH;
            if(!heights.count(right))
                heights[right] = rightH;

            ans[i] = i > 0 ? max(ans[i-1], maxH) : maxH;
        }
        return ans;
    }
};