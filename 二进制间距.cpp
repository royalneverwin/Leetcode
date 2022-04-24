class Solution {
public:
    int binaryGap(int n) {
        vector<bool> bi(32, 0);
        int index = 0;
        while(n > 0){
            bi[index] = n % 2;
            n /= 2;
            index++;
        }

        int preOne = -1;
        int ans = 0;
        for(int i = 0; i < index; i++){
            if(bi[i]){
                if(preOne != -1){
                    ans = max(ans, i - preOne);
                }
                preOne = i;
            }
        }

        return ans;



    }
};