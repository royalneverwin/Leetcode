class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int length = rectangles.size();
        int maxLen = 0, cnt = 0;
        for(int i = 0; i < length; i++){
            int tmp = min(rectangles[i][0], rectangles[i][1]);
            if(tmp > maxLen){
                maxLen = tmp;
                cnt = 1;
            }
            else if(tmp == maxLen)
                cnt++;
        }
        return cnt;
    }
};