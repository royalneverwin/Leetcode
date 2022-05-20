class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first == second)
            return true;
        if(first.length() == second.length()){
            for(int i = 0; i < first.length(); i++){
                if(first[i] != second[i]){
                    first[i] = second[i];
                    if(first != second)
                        return false;

                    return true;
                }
            }

            return true; // 虽然不可能达到
        }
        else if(first.length() == second.length() + 1){
            int i1 = 0, i2 = 0;
            bool flag = true;
            while(i2 < second.length()){
                if(first[i1] != second[i2]){ // 删去first[i1]
                    if(flag){
                        i1++;
                        flag = false;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    i1++;
                    i2++;
                }
            }

            return true;
        }
        else if(first.length() == second.length() - 1){
            int i1 = 0, i2 = 0;
            bool flag = true;
            while(i1 < second.length()){
                if(first[i1] != second[i2]){ // 删去second[i2]
                    if(flag){
                        i2++;
                        flag = false;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    i1++;
                    i2++;
                }
            }

            return true;
        }
        else
            return false;
    }
};