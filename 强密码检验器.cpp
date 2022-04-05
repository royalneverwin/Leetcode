class Solution {
public:
    int strongPasswordChecker(string password) {
        bool ifSmall = false, ifBig = false, ifNum = false;
        for(int i = 0; i < password.length(); i++){ // 寻找是否有小写、大写和数字
            if(password[i] >= 'a' && password[i] <= 'z')
                ifSmall = true;
            else if(password[i] >= 'A' && password[i] <= 'Z')
                ifBig = true;
            else if(password[i] >= '0' && password[i] <= '9')
                ifNum = true;
        }
        int cnt = 0;
        // 贪心
        if(password.length() < 6){ // 需要加数字
            int add = 6 - password.length();
            if(password.length() < 3){ // 不存在三个连续 而且补到6个后肯定满足其他条件
                return add;
            }
            for(int i = 2; i < password.length(); i++){ // 先处理三个连续的情况
                if(password[i] == password[i-1] && password[i-1] == password[i-2]){ // 优先插入 且插入需要加的成分
                    if(ifSmall == false){
                        ifSmall = true;
                    }
                    else if(ifBig == false){
                        ifBig = true;
                    }
                    else if(ifNum == false){
                        ifNum = true;
                    }
                    if(add > 0){
                        password[i-1] = '#'; // 模拟插入
                        add--;
                    }
                    else
                        password[i] = '$'; // 模拟修改
                    cnt++;
                }
            }
            int left = (!ifSmall) + (!ifBig) + (!ifNum);
            return cnt + max(add, left);
        }

        else if(password.length() > 20){ // 需要删 比较复杂
            int sub = password.length() - 20;
            // 先删只用删一个的 再删只用删两个的 最后删要删三个的
            multiset<int> tmp;
            vector<multiset<int>> check(3, tmp);
            for(int i = 0; i < password.size()-2; i++){
                int j = i+1;
                while(j < password.size() && password[j] == password[i])
                    j++;
                if((j-i) >= 3){
                    check[(j-i)%3].insert(j-i);
                }
                i = j-1;
            }
            for(int i = 0; i < 3; i++){
                while(sub > 0 && check[i].size()){
                    auto j = check[i].begin();
                    if(sub >= i+1){
                        sub -= i+1;
                        if(*j - (i+1) >= 3){
                            check[2].insert(*j-(i+1));
                        }
                        check[i].erase(j);
                        cnt += i+1;
                    }
                    else{
                        check[(*j - sub) % 3].insert(*j - sub);
                        check[i].erase(j);
                        cnt += sub;
                        sub = 0;
                    }
                }
            }
            int sum = 0;
            for(int i = 0; i < 3; i++){ // 对剩下连续的aaa修改
                for(auto &j: check[i]){
                    sum += j / 3;
                }
            }
            sum = max(sum, (!ifSmall) + (!ifBig) + (!ifNum));
            return cnt + sum + sub;
        }

        else{
            for(int i = 2; i < password.size(); i++){
                if(password[i] == password[i-1] && password[i-1] == password[i-2]){ // 优先改
                    password[i] = '$'; // 模拟改
                    if(ifSmall == false)
                        ifSmall = true;
                    else if(ifBig == false)
                        ifBig =true;
                    else if(ifNum == false)
                        ifNum = true;
                    cnt++;
                }
            }
            int left = (!ifSmall) + (!ifBig) + (!ifNum);
            return cnt + left;
        }
    }
};