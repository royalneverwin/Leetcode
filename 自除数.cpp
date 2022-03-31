class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            int num = i;
            int divide;
            bool flag = false;
            while(num > 0){
                divide = num % 10;
                if(!divide || i % divide){
                    flag = true;
                    break;
                }
                num /= 10;
            }
            if(!flag)
                ans.push_back(i);
        }
        return ans;
    }
};