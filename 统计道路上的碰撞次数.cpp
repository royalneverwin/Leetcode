class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        for(int i = 0; i < directions.length(); i++){
            if(directions[i] == 'L'){
                if(i == 0)
                    continue;
                else if(directions[i-1] != 'L'){
                    ans++;
                    directions[i] = 'S';
                }
            }
        }
        for(int i = directions.length()-1; i >= 0; i--){
            if(directions[i] == 'R'){
                if(i == directions.length()-1)
                    continue;
                else if(directions[i+1] != 'R'){
                    directions[i] = 'S';
                    ans++;
                }
            }
        }
        return ans;
    }
};