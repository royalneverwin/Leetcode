class Solution {
public:
    // 正常的算法
    // 按照正常排序的计算方法
    string getPermutation(int n, int k) {
        string ans = "123456789"; // 最多就9个

        int cnt = 1;

        while(cnt < k){
            int index = n - 1;
            while(index > 0 && ans[index] < ans[index - 1])
                index--;

            int change = index - 1; // 第一个互换的index
            int minIndex;
            char minNum = '9'+1;

            // 找第二个互换的index
            for(int i = index; i < n; i++){
                if(ans[i] > ans[change] && ans[i] < minNum){
                    minNum = ans[i];
                    minIndex = i;
                }
            }

            // swap
            char tmp = ans[change];
            ans[change] = ans[minIndex];
            ans[minIndex] = tmp;

            // sort
            sort(ans.begin() + index, ans.begin() + n);

            cnt++;
        }


        return ans.substr(0, n);
    }
};



class Solution {
public:
    // 数学问题
    // 给定第一个数字 一共(n-1)!种可能
    // 故k <= (n-1)!, 第一个数字是1, (n-1)! < k <= 2*(n-1)!, 第一个数字是2,..., 以此类推
    // 所以第一个数字是 k / (n-1)! + 1
    // 剩余的k是k' = k % (n-1)!, 对应n-1个数, 转化成了子问题
    int f(int k){
        int ret = 1;
        for(int i = k; i >= 1; i--){
            ret *= i;
        }
        return ret;
    }

    string getPermutation(int n, int k) {
        bool flag[10] = {0};
        string ans = "";
        int cnt = n;
        for(int i = 0; i < n; i++){
            int num = k / f(cnt-1);

            if(k % f(cnt-1) != 0){
                num += 1;
            }
            k -= (num-1) * f(cnt-1); // 更新k
            cnt = cnt-1;  // 更新cnt

            int tmp = 0;
            for(int j = 1; j <= 9; j++){
                if(flag[j] == false){
                    tmp++;
                    if(tmp == num){
                        flag[j] = true;
                        ans += '0' + j;
                        break;
                    }
                }
            }

        }

        return ans;
    }
};