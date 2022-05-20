class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 涉及元素极多做不到遍历的二维矩阵里的第K小都可以用二分猜答案的套路，转化为“给定一个数，
        // 求矩阵中有多少个数比这个数小”，进而实现二分查找，主站378，719，786，2040题也是类似的思路
        //（其中2040题实现细节极多，代码冗长，导致了rating很高），第一次见到这类题想不出做法很正常，
        // 但这个经典套路还是必须掌握~

        // 公式如下：n * (x / n) + /sum_i (x / i)


        int left = 1;
        int right = m * n;
        while(left < right){
            cout << left << ' ' << right << ' ';
            int x = (left + right) / 2;
            int result = n * (x / n);
            for(int i = x / n + 1; i <= m; i++){
                result += x / i;
            }

            cout << x << ' ' << result << endl;
            // MARK! result == k的时候不能立即返回， 因为不比x大的数 == k的时候，x 不一定在乘法表里 
            // 所以这时候只能更新right = x，然后继续查找，找到最小的 result == k的值 才是最终结果
            // if(result == k)
            //     return x;
            if(result < k)
                left = x + 1;
            else
                right = x;
        }

        return left;
    }
};