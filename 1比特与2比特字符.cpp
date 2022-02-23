class Solution {
public:
    bool Flag(vector<int>& bits, int length){
        if(length == 0)
            return true;
        else if(length == 1){
            if(bits[0] == 0)
                return true;
            else
                return false;
        }
        else if(length == 2){
            if(bits[0] == 0 && bits[1] == 0)
                return true;
            else if(bits[0] == 1 && bits[1] == 0)
                return true;
            else if(bits[0] == 1 && bits[1] == 1)
                return true;
            else
                return false;
        }
        else{ // length >= 3
            if(bits[length-1] == 0){
                if(Flag(bits, length-1))
                    return true;
            }
            if(bits[length-1] == 1 && bits[length-2] == 1){
                if(Flag(bits, length-2))
                    return true;
            }
            if(bits[length-1] == 0 && bits[length-2] == 1){
                if(Flag(bits, length-2))
                    return true;
            }
            return false;
        }
    }
    bool isOneBitCharacter(vector<int>& bits) {
        int length = bits.size();
        if(bits[length-1] == 0){ // 最后一个不是0 肯定不是

            if(Flag(bits, length-1)) // 判断剩下的能不能被表示
                return true;
        }
        return false;
    }
};


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // 只需要看最后的0前面有几个1就行
        int length = bits.size();
        if(bits[length-1] == 0){ // 最后一个不是0 肯定不是
            int cnt = 0;
            for(int i = length-2; i >= 0; i--){
                if(bits[i] == 1)
                    cnt++;
                else
                    break;
            }
            if(cnt % 2 == 0)
                return true;
        }
        return false;
    }
};