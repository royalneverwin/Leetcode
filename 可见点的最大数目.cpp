class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans = 0;
        int length = points.size();
        vector<double>angleArray(length); // 点和点的连线与location向x正半轴直线的夹角, 范围（-180, 180）
        for(int i = 0; i < length; i++){
            if(points[i][0] == location[0] && points[i][1] == location[1]){
                ans++;
                angleArray[i] = -300; // out of account, can be seen in any cases
            }
            else // use atan2(), brilliant!
                angleArray[i] = atan2(points[i][1] - location[1],
                                      points[i][0] - location[0])  / M_PI * 180;

        }
        sort(angleArray.begin(), angleArray.end());
        // 不能写angleArray.end()！angleArray比length更大一点
        // array数组提前开的, 所以要注意！
        int minIndex = 0;
        for(minIndex = 0; minIndex < length; minIndex++){ // preprocess
            if(angleArray[minIndex] != -300)
                break;
        }
        int mark = minIndex; //mark一下, 后面更新maxIndex会用到
        int maxIndex = minIndex;
        int tmp = ans; // hold the number's change
        while(maxIndex < length){
            while(maxIndex < length && angleArray[maxIndex] - angleArray[minIndex] <= angle){
                tmp++;
                maxIndex++;
            }
            ans = max(ans, tmp);
            while(maxIndex < length && angleArray[maxIndex] - angleArray[minIndex] > angle){
                minIndex++;
                tmp--;
            }
        }
        // maxIndex = length, change maxIndex to mark
        maxIndex = mark;
        while(minIndex < length){
            while(maxIndex < minIndex && 360 - angleArray[minIndex]
                                         + angleArray[maxIndex] <= angle){
                tmp++;
                maxIndex++;
            }
            ans = max(ans, tmp);
            while(minIndex < length && 360 - angleArray[minIndex]
                                       + angleArray[maxIndex] > angle){
                tmp--;
                minIndex++;
            }
        }
        return ans;
    }
};