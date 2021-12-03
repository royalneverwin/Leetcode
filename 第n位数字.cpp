class Solution {
public:
    unsigned int F(int n){
        if(n < 10)
            return 1;
        else if(n < 100)
            return 2;
        else if(n < 1000)
            return 3;
        else if(n < 10000)
            return 4;
        else if(n < 100000)
            return 5;
        else if(n < 1000000)
            return 6;
        else if(n < 10000000)
            return 7;
        else if(n < 100000000)
            return 8;
        else if(n < 1000000000)
            return 9;
        else
            return 10;
    }

    string G(int n){
        string ret = "";
        while(n >= 10){
            ret.append(1, '0' + n % 10);
            n /= 10;
        }
        ret.append(1, '0' + n);
        return ret;
    }

    int findNthDigit(int n) {
        int index = 1;
        unsigned int cnt = 0; // 用unsigned int, 否则对MAX_INT会超时
        while(cnt < n){
            cnt += F(index);
            index++;
        }
        index--;
        cnt -= F(index);
        int left = n - cnt; // index的第left位
        string num = G(index);
        return num[num.length() - left] - '0';
    }
};




class Solution {
public:
    string G(int n){
        string ret = "";
        while(n >= 10){
            ret.append(1, '0' + n % 10);
            n /= 10;
        }
        ret.append(1, '0' + n);
        return ret;
    }

    // 先把n分到一类数（长度相同）中，再找到n是这一类数中的第几个的位数
    int findNthDigit(int n) {
        int range[9];
        for(int i = 1; i <= 8; i++) //i 最多只可能有9位
            range[i] = 9 * (int)pow(10, i-1) * i;
        int index = -1;
        for(int i = 1; i <= 8; i++){
            if(range[i] >= n){
                index = i;
                break;
            }
            else
                n -= range[i];
        }
        if(index == -1) // 10位数
            index = 9;
        int cnt = n / index;
        if(n % index != 0)
            cnt++;
        int num = (int)pow(10, index - 1) + cnt - 1;
        n -= (cnt - 1) * index;
        string snum = G(num);
        return snum[snum.length() - n] - '0';

    }
};