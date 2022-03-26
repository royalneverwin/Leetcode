class Solution {
public:
    void A(string& ans, int k, int l){ // 任何l长度都可以
        if(k == 1) // 不需要再加
            return;
        int cnt = 1;
        int lastCnt = 1;
        for(int i = 0; i <= 9; i++){
            int add = 1;
            for(int j = 0; j < l; j++){
                cnt += add;
                add *= 10;
            }
            if(cnt >= k){
                ans.append(1, i + '0');
                k -= lastCnt;
                break;
            }
            else{
                lastCnt = cnt;
            }
        }
        if(l > 1)
            A(ans, k, l-1);
    }

    void C(string& ans, int k, int l){ // 最多l-1长度
        if(k == 1) // 不需要再加
            return;
        int cnt = 1;
        int lastCnt = 1;
        for(int i = 0; i <= 9; i++){
            int add = 1;
            for(int j = 0; j < l-1; j++){
                cnt += add;
                add *= 10;
            }
            if(cnt >= k){
                ans.append(1, i + '0');
                k -= lastCnt;
                break;
            }
            else{
                lastCnt = cnt;
            }
        }
        if(l > 1)
            C(ans, k, l-1);
    }

    void B(string& ans, int k, const string& s, int n){ // 和s做判断
        if(k == 1) // 不需要再做判断
            return;
        int firstOne = s[0] - '0';
        int cnt = 1;
        int l = s.length();
        int lastCnt = 1;
        int i;
        for(i = 0; i <= 9; i++){ // 计算i开头的一共多少个
            if(i < firstOne){
                int add = 1;
                for(int j = 0; j < l; j++){
                    cnt += add;
                    add *= 10;
                }
            }
            else if(i == firstOne){
                int add = 1;
                for(int j = 0; j < l-1; j++){
                    cnt += add;
                    add *= 10;
                }
                cnt += (n-i*add)+1;
            }
            else{
                int add = 1;
                for(int j = 0; j < l-1; j++){
                    cnt += add;
                    add *= 10;
                }
            }
            if(cnt >= k){ // 大了, 说明就是以i开头
                ans.append(1, i + '0');
                k -= lastCnt; // 更新k
                break;
            }
            else{ // 记录上一个cnt方便更新k
                lastCnt = cnt;
            }
        }
        if(i < firstOne){ // 去函数A, 任何l长度都可以
            A(ans, k, l-1);
        }
        else if(i == firstOne){ // 去函数B, 根据s判断
            B(ans, k, s.substr(1, l-1), n % (int)pow(10, l-1));
        }
        else{ // 去函数C, 任何l长度都不可以
            C(ans, k, l-1);
        }
    }
    void F(string& ans, int k, const string& s, int n){
        int firstOne = s[0] - '0';
        int cnt = 0;
        int l = s.length();
        int lastCnt = 0;
        int i;
        for(i = 1; i <= 9; i++){ // 计算i开头的一共多少个
            if(i < firstOne){
                int add = 1;
                for(int j = 0; j < l; j++){
                    cnt += add;
                    add *= 10;
                }
            }
            else if(i == firstOne){
                int add = 1;
                for(int j = 0; j < l-1; j++){
                    cnt += add;
                    add *= 10;
                }
                cnt += (n - i * add)+1;
            }
            else{
                int add = 1;
                for(int j = 0; j < l-1; j++){
                    cnt += add;
                    add *= 10;
                }
            }
            if(cnt >= k){ // 大于等于, 说明就是以i开头
                ans.append(1, i + '0');
                k -= lastCnt; // 更新k
                break;
            }
            else{ // 记录上一个cnt方便更新k
                lastCnt = cnt;
            }
        }
        if(i < firstOne && l > 1){ // 去函数A, 任何l长度都可以
            A(ans, k, l-1);
        }
        else if(i == firstOne && l > 1){ // 去函数B, 根据s判断
            B(ans, k, s.substr(1, l-1), n % (int)pow(10, l-1));
        }
        else if(l > 1){ // 去函数C, 任何l长度都不可以
            C(ans, k, l-1);
        }
    }
    int findKthNumber(int n, int k) {
        string s = to_string(n);
        string ans;
        F(ans, k, s, n);
        return stoi(ans);
    }
};


// 字典树解法
class Solution {
public:
    // 字典树！
    // 前序遍历
    // 如何求节点的所有子节点？
    // first_i是第一个节点, last_i是最后一个
    // first_i = first_i-1 * 10, last_i = last_i-1 * 10 + 9
    int getChildCnt(int n, long node){
        int cnt = 0;
        long first = node * 10;
        long last = node * 10 + 9;
        while(n >= first){
            if(n > last){
                cnt += last - first + 1;
            }
            else{
                cnt += n - first + 1;
                break;
            }
            first = first * 10;
            last = last * 10 + 9;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        while(k > 0){
            int cnt = getChildCnt(n, ans);
            if(cnt < k){ // 跳到兄弟节点
                ans += 1;
                k -= cnt+1;
            }
            else{ // 跳到最左边的节点
                ans *= 10;
                k--;
            }
        }
        return ans;
    }
};