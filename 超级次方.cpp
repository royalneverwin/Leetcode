class Solution {
public:
    // 普通方法
    int firstNotZero = 0;
    int Divide(vector<int>& b, int n){ // b = b / n, and return b % n, if b < n then return -1
        int length = b.size();
        if(firstNotZero == length - 1 || firstNotZero == length - 2){
            if(GetNum(b) < n)
                return -1;
        }
        int num = 0;
        bool ifZero = true;
        for(int i = firstNotZero; i < b.size(); i++){
            if(b[i] == 0 && ifZero){
                firstNotZero = i;
                continue;
            }
            else if(ifZero){
                firstNotZero = i;
                ifZero = false;
            }
            num += b[i];
            if(num >= n){
                b[i] = num / n;
                num = num % n;
            }
            else{
                b[i] = 0;
            }
            num *= 10;
        }
        num /= 10;
        return num; //num is b % n
    }
    int GetNum(vector<int> &b){// b must <= 11
        int length = b.size();
        if(length == 1)
            return b[0];
        return b[length - 1] + 10 * b[length - 2];
    }
    int superPow(int a, vector<int>& b) {
        int aa = a;
        int i;
        int left = 1;
        while(1){
            a = aa % 1337; // only need a % 1337
            if(a == 1)
                return 1;
            else if(a == 0)
                return 0;
            else{
                for(i = 1; i <= 11; i++){
                    if((int)pow(a, i) >= 1337){
                        break;
                    }
                }
                aa = (int)pow(a, i); // aa = a^i > 1337 and a^(i-1) < 1337
                int tmp = Divide(b, i);
                // cout << "i = " << i << endl;
                // cout << "aa = " << aa << endl;
                // cout << "tmp = " << tmp << endl;
                // for(int i = 0; i < b.size(); i++){
                //     cout << b[i];
                // }
                // cout << endl;
                if(tmp == -1){ // b < i
                    return ((int)pow(a, GetNum(b)) * left) % 1337;
                }
                else if(tmp > 0){ // save a^tmp in left 
                    left *= (int)pow(a, tmp);
                    left = left % 1337;
                }
                // cout << "left = " << left << endl;
            }
        }
    }
};


class Solution {
public:
    // 递归计算
    // 每次计算b的最后一位
    int MyPow(int a, int b){
        if(b == 0)
            return 1;
        a = a % 1337;
        int ret = 1;
        while(b > 1){
            if(b & 1 != 0)
                ret = (ret * a) % 1337;
            a = (a * a) % 1337;
            b >>= 1;
        }
        return (ret * a) % 1337;
    }

    int Loop(int a, vector<int>& b, int index){
        if(index < 0){
            return 1;
        }
        return (MyPow(Loop(a, b, index-1), 10) * MyPow(a, b[index])) % 1337;
    }
    int superPow(int a, vector<int>& b) {
        if(a == 1)
            return 1;
        else if(a % 1337 == 0)
            return 0;
        else
            return Loop(a, b, b.size() - 1);
    }
};