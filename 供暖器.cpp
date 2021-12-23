class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int index1 = 0;
        int index2 = 0;
        int length1 = houses.size();
        int length2 = heaters.size();
        int ans = 0;
        int dis1, dis2;
        // 注意第一个houses也要找前后的heaters！
        int tmp = index2;
        if(houses[index1] <= heaters[index2]){ // 前面没有heaters
            ans = heaters[index2] - houses[index1];
        }
        else{
            while(tmp < length2 && heaters[tmp] < houses[index1]){
                index2 = tmp;
                tmp++;
            }
            if(tmp == length2){
                ans = houses[length1-1] - heaters[index2];
                return ans;
            }
            // heaters[tmp] >= houses[index1] > heaters[index2], 看houses[index1]用哪个最近
            dis1 = heaters[tmp] - houses[index1];
            dis2 = houses[index1] - heaters[index2];
            if(dis1 <= dis2){
                ans = dis1;
                index2 = tmp;
                index1++;
            }
            else{
                ans = dis2;
                index1++;
            }
        }
        while(index1 < length1){
            if(abs(houses[index1] - heaters[index2]) <= ans) // 能被前一个heaters覆盖
                index1++;
            else{ // houses[index1]肯定 > heaters[index2]
                tmp = index2;
                while(tmp < length2 && heaters[tmp] < houses[index1]){
                    index2 = tmp;
                    tmp++;
                }
                if(tmp == length2){ // index2是最后一个heaters
                    ans = max(houses[length1-1] - heaters[index2], ans);
                    return ans;
                }
                // heaters[tmp] >= houses[index1] > heaters[index2], 看houses[index1]用哪个最近
                dis1 = heaters[tmp] - houses[index1];
                dis2 = houses[index1] - heaters[index2];
                if(dis1 <= ans){
                    index1++;
                    index2 = tmp;
                }
                else if(dis2 <= ans){
                    index1++;
                }
                else if(dis1 <= dis2){
                    ans = dis1;
                    index1++;
                    index2 = tmp;
                }
                else{
                    ans = dis2;
                    index1++;
                }
            }
        }
        return ans;
    }
};