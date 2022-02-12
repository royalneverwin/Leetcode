class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        int last = -1; // 0是a, 1是b, 2是c
        int llast = -1; // 0是a, 1是b, 2是c

        // 优先写多的那个
        while(1){
            if(a == 0 && b == 0 && c == 0) // 都填完了
                break;
            if(a >= b && a >= c){
                if(last == 0 && llast == 0){ // 已经有两个了
                    if(b == 0 && c == 0) // 没法再填了
                        break;
                    else if(b >= c){
                        ans += 'b';
                        llast = last;
                        last = 1;
                        b--;
                    }
                    else{
                        ans += 'c';
                        llast = last;
                        last = 2;
                        c--;
                    }

                }
                else{
                    ans += 'a';
                    llast = last;
                    last = 0;
                    a--;
                }
            }
            else if(b >= a && b >= c){
                if(last == 1 && llast == 1){ // 已经有两个了
                    if(a == 0 && c == 0) // 没法再填了
                        break;
                    else if(a >= c){
                        ans += 'a';
                        llast = last;
                        last = 0;
                        a--;
                    }
                    else{
                        ans += 'c';
                        llast = last;
                        last = 2;
                        c--;
                    }

                }
                else{
                    ans += 'b';
                    llast = last;
                    last = 1;
                    b--;
                }
            }
            else{
                if(last == 2 && llast == 2){ // 已经有两个了
                    if(b == 0 && a == 0) // 没法再填了
                        break;
                    else if(b >= a){
                        ans += 'b';
                        llast = last;
                        last = 1;
                        b--;
                    }
                    else{
                        ans += 'a';
                        llast = last;
                        last = 0;
                        a--;
                    }

                }
                else{
                    ans += 'c';
                    llast = last;
                    last = 2;
                    c--;
                }
            }
        }
        return ans;
    }
};