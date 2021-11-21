class Solution {
public:
    struct point{
        unsigned int n;
        int cnt;
        point(int nn, int c): n(nn), cnt(c){}
    };
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
        queue<point> qp;
        qp.push(point(n, 0));
        while(!qp.empty()){
            point tmp = qp.front();
            qp.pop();
            tmp.cnt++;
            if(tmp.n % 2 == 0){
                tmp.n /= 2;
                if(tmp.n == 1)
                    return tmp.cnt;
                qp.push(tmp);
            }
            else{
                tmp.n += 1;
                qp.push(tmp);
                tmp.n -= 2;
                qp.push(tmp);
            }
        }
        return -1;
    }
};


class Solution {
public:
    // 通过位运算知识我们可以知道, 当x+1或x-1时, x的第0位一定是1, 当x的第1位是1时, +1会导致出现更多的0位,
    // x可以通过/2变小的更快; 当x的第1位是0时, x+1和x-1导致x/2的次数不会变, 此时优先选择x-1使x变得更小.
    // 最后特殊处理x = 3即可
    int integerReplacement(int n) {
        int cnt = 0;
        unsigned int num = n;
        while(num != 1){
            if(num % 2 == 0)
                num /= 2;
            else if((num >> 1) & 1 && num != 3)
                num = num + 1;
            else
                num = num - 1;
            cnt++;
        }
        return cnt;
    }
};