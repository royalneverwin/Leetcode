class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx < sx || ty < sy) // 一定要比初始点大
            return false;

        if(tx == sx && ty == sy)
            return true;

        // 反向计算
        // (sx,sy)推(tx,ty)太难了
        // 从(tx,ty)推(sx,sy)
        // if tx == ty 初始状态
        // elif tx > ty 则tx是和
        // elif ty > tx 则ty是和
        while(tx != ty && tx > sx && ty > sy){
            if(tx > ty){
                int sub = (tx - ty) % ty;
                tx = sub;
            }
            else{
                int sub = (ty - tx) % tx;
                ty = sub;
            }
        }
        if(tx == ty){
            if(tx == sx && ty == sy)
                return true;
            else
                return false;
        }
        else if(tx == sx){
            if((ty - sy) % sx != 0)
                return false;
            else
                return true;
        }
        else if(ty == sy){
            if((tx - sx) % sy != 0)
                return false;
            else
                return true;
        }
        else
            return false;
    }
};