class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int index = 0;
        int left = 0;
        int cnt;
        while(index < data.size()){
            int perData = data[index] & 0xFF;
            if(left == 0){ // 这是一个UTF-8的开头
                int bias = 0x80;
                cnt = 0;
                while((perData & bias) != 0){
                    cnt++;
                    bias >>= 1;
                }
                if(cnt > 4)
                    return false;
                else if(cnt == 1)
                    return false;
                else if(cnt > 1)
                    left = cnt-1;
            }
            else{ // 这不是UTF-8的开头
                int bias1 = 0x80;
                int bias2 = 0x40;
                if((perData & bias1) != bias1 || (perData & bias2) != 0){
                    return false;
                }
                left--;
            }
            index++;
        }
        if(left != 0){
            return false;
        }
        return true;
    }
};