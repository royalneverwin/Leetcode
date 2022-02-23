class Solution {
public:
    // BFS会简单很多 懒得写了
    // 双指针模拟也会简单很多 懒得写了

    string pushDominoes(string dominoes) {
        // 如果对向倒也会都倒下
        unordered_set<int> toLeft;
        unordered_set<int> toRight;
        for(int i = 0; i < dominoes.length(); i++){
            if(dominoes[i] == 'L'){
                if(i != 0 && dominoes[i-1] == '.') // 否则对左侧没有影响
                    toLeft.insert(i);
            }
            else if(dominoes[i] == 'R'){
                if(i != dominoes.length()-1 && dominoes[i+1] == '.') // 否则对右侧没有影响
                    toRight.insert(i);
            }
        }

        while(toLeft.size() != 0 && toRight.size() != 0){
            vector<int> nextAddLeft;
            vector<int> nextAddRight;
            vector<int> nextSubLeft;
            vector<int> nextSubRight;
            for(auto &i: toLeft){ // 只需要对toLeft检查是否存在抵消即可
                nextSubLeft.push_back(i);
                if(dominoes[i-1] == '.'){
                    if(i-1 == 0){ // i-1左边没东西了
                        dominoes[0] = 'L';
                    }
                    else if(dominoes[i-2] == 'R'){ // i-1左边往右倒 抵消了
                        toRight.erase(i-2);
                    }
                    else{ // i-1正常往左
                        dominoes[i-1] = 'L';
                        nextAddLeft.push_back(i-1);
                    }
                }
            }

            for(auto &i: toRight){ // 直接操作
                nextSubRight.push_back(i);
                if(dominoes[i+1] == '.'){
                    dominoes[i+1] = 'R';
                    if(i+1 != dominoes.length() - 1){
                        nextAddRight.push_back(i+1);
                    }
                }
            }

            // 修改toLeft、toRight
            for(auto &i: nextAddLeft)
                toLeft.insert(i);
            for(auto &i: nextSubLeft)
                toLeft.erase(i);
            for(auto &i: nextAddRight)
                toRight.insert(i);
            for(auto &i: nextSubRight)
                toRight.erase(i);
        }


        while(toLeft.size() != 0){ // 只剩下向左的
            vector<int> nextAddLeft;
            vector<int> nextSubLeft;
            for(auto &i: toLeft){
                nextSubLeft.push_back(i);
                if(dominoes[i-1] == '.'){
                    dominoes[i-1] = 'L';
                    if(i-1 != 0 && dominoes[i-2] == '.'){
                        nextAddLeft.push_back(i-1);
                    }
                }
            }
            for(auto &i: nextAddLeft)
                toLeft.insert(i);
            for(auto &i: nextSubLeft)
                toLeft.erase(i);
        }

        while(toRight.size() != 0){ // 只剩下向右的
            vector<int> nextAddRight;
            vector<int> nextSubRight;
            for(auto &i: toRight){
                nextSubRight.push_back(i);
                if(dominoes[i+1] == '.'){
                    dominoes[i+1] = 'R';
                    if(i+1 != dominoes.length() - 1 && dominoes[i+2] == '.'){
                        nextAddRight.push_back(i+1);
                    }
                }
            }
            for(auto& i: nextAddRight)
                toRight.insert(i);
            for(auto &i: nextSubRight)
                toRight.erase(i);
        }
        return dominoes;
    }
};