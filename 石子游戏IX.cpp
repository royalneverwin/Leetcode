class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Alice 开头 只会选mod = 1或mod = 2
        // 开头：
        // 若Alice选了mod = 1，Bob也会选mod = 1或mod = 0
        // 若Alice选了mod = 2，Bob也会选mod = 2或mod = 0
        // 之后：
        // 若一人选了mod = 2，另一人会选mod = 1或mod = 0
        // 若一人选了mod = 1，另一人会选mod = 2或mod = 0
        // 若一人选了mod = 0，另一人也会选mod = 0或和目前和相同的mod
        // 故 只要让另一人无数可选 就赢了
        // 综合顺序：a, a, b, a, b, a, b..., 其中0穿插其中
        // Alice赢的途径：让Bob打破上述循环
        // Bob赢的途径：让Alice打破上述循环或移除全部石子

        int cnt[3] = {0, 0, 0};
        for(int i = 0; i < stones.size(); i++){
            if(stones[i] % 3 == 0){
                cnt[0]++;
            }
            else if(stones[i] % 3 == 1){
                cnt[1]++;
            }
            else{
                cnt[2]++;
            }
        }
        if(cnt[1] == 0 && cnt[2] == 0) // 只有三的倍数, Alice肯定输
            return false;
        cnt[0] = cnt[0] % 2;
        if(cnt[0] == 0){ // 视为没有0
            if(cnt[1] == 0 || cnt[2] == 0) // 只有mod1 或2, Alice肯定输
                return false;
            else // Alice一定赢
                return true;
        }
        else{ // 有一个0
            if(cnt[1] <= 2 && cnt[2] <= 2) // Alice会输
                return false;
            else if(cnt[1] == 0 || cnt[2] == 0) // Alice会赢
                return true;
            else if(cnt[1] > cnt[2] + 2 || cnt[2] > cnt[1] + 2) // Alice赢
                return true;
            else // Alice输
                return false;

        }
    }
};