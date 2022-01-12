class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int maxT = releaseTimes[0];
        for(int i = 1; i < keysPressed.length(); i++){
            if(releaseTimes[i] - releaseTimes[i-1] > maxT){
                ans = keysPressed[i];
                maxT = releaseTimes[i] - releaseTimes[i-1]; // 更新maxT
            }else if(releaseTimes[i] - releaseTimes[i-1] == maxT){
                if(keysPressed[i] > ans)
                    ans = keysPressed[i];
            }
        }
        return ans;
    }
};