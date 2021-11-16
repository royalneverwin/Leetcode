class Solution {
public:
    //大矩形面积 = 小矩形面积和
    //不存在重叠部分
    //第一个非常容易判断，第二个：我们知道如果矩形出现重叠，就一定会有如下情况：
    //大矩形四角的点出现次数为1次，其余点出现次数为2次或4次
    struct Point{
        int x;
        int y;
        Point(int xx, int yy): x(xx), y(yy){}
        bool operator < (const struct Point& other) const{
            return x != other.x ? x < other.x : y < other.y;
        }
    };
    void Operator(int x, int y, map<Point, int> &mapPoint){
        if(mapPoint.find(Point(x, y)) == mapPoint.end()){
            mapPoint[Point(x, y)] = 1;
        }
        else{
            mapPoint[Point(x, y)]++;
        }
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int sumS = 0;
        int minx = 100000, miny = 100000, maxa = -100000, maxb = -100000;
        map<Point, int> mapPoint;
        for(auto &rec: rectangles){
            if(rec[0] < minx){
                minx = rec[0];
            }
            if(rec[1] < miny){
                miny = rec[1];
            }
            if(rec[2] > maxa){
                maxa = rec[2];
            }
            if(rec[3] > maxb){
                maxb = rec[3];
            }
            Operator(rec[0], rec[1], mapPoint);
            Operator(rec[0], rec[3], mapPoint);
            Operator(rec[2], rec[1], mapPoint);
            Operator(rec[2], rec[3], mapPoint);
            sumS += (rec[2] - rec[0]) * (rec[3] - rec[1]);
        }
        int S = (maxa - minx) * (maxb - miny);
        if(S != sumS){ //判断总面积是不是相同
            // cout << 1 << endl;
            return false;
        }
        if(mapPoint[Point(minx, miny)] != 1 ||
           mapPoint[Point(minx, maxb)] != 1 ||
           mapPoint[Point(maxa, miny)] != 1 ||
           mapPoint[Point(maxa, maxb)] != 1) //判断边缘的点是不是只出现了一次
            return false;
        for(auto &i: mapPoint){
            if(i.second % 2 != 0){
                if((i.first.x != minx || i.first.y != miny) &&
                   (i.first.x != maxa || i.first.y != maxb) &&
                   (i.first.x != minx || i.first.y != maxb) &&
                   (i.first.x != maxa || i.first.y != miny)){ //判断除了边缘处的点是不是只出现了偶数次
                    // cout << i.first.x << ' ' << i.first.y << endl;
                    // cout << 2 << endl;
                    return false;
                }
            }
        }
        return true;
    }
};