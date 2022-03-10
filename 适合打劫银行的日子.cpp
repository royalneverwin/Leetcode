// 猪鼻方法
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int len = security.size();
        int cnt = 0;
        int beginIndex;
        int firstEqualIndex;
        int index = 1;
        bool flag;
        vector<int> ans;
        if(time == 0){ // 特殊处理time = 0的情况
            ans = vector<int>(len, 0);
            for(int i = 0; i < len; i++)
                ans[i] = i;
            return ans;
        }

        while(1){
            cnt = 0;
            for(; index < len - time; index++){ // 找到起始点
                if(security[index] <= security[index-1]){
                    cnt++;
                    if(cnt == time){
                        beginIndex = index;
                        break;
                    }
                }
                else{
                    cnt = 0;
                }
            }
            if(index >= len - time)
                break;
            index = beginIndex;
            firstEqualIndex = -1;
            cnt = 0;
            flag = false;
            while(beginIndex < len - time){ // 判断后续是否符合
                while(cnt < time){
                    if(security[index+1] > security[index]){
                        flag = true;
                        cnt++;
                    }
                    else if(security[index+1] == security[index]){
                        if(firstEqualIndex == -1)
                            firstEqualIndex = index;
                        cnt++;
                    }
                    else
                        break;
                    index++;
                }
                // 结束后更新beginIndex
                if(cnt == time){
                    ans.push_back(beginIndex);
                    if(firstEqualIndex == beginIndex){ // 第一个等号就在beginIndex
                        index = beginIndex + 1;
                        while(index < beginIndex + time && security[index + 1] != security[index]){
                            index++;
                        }
                        if(security[index+1] == security[index])
                            firstEqualIndex = index;
                        else
                            firstEqualIndex = -1;
                        index = beginIndex + time;
                        beginIndex++;
                        cnt = time-1;
                    }
                    else if(firstEqualIndex == -1){ // 没有相等的，从前缀重找
                        index = beginIndex + time + 1;
                        break;
                    }
                    else{
                        index = firstEqualIndex + 1;
                        break;
                    }
                }
                else{ // 从断点后重新找
                    if(!flag){ // 不存在升的, 从下一个开始找后缀
                        beginIndex += cnt + 1;
                        index = beginIndex;
                        cnt = 0;
                        flag = false;
                    }
                    else{ // 存在升的
                        index = beginIndex + cnt + 1;
                        break;
                    }
                }
            }
            if(beginIndex >= len - time)
                break;
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // 动态规划
        // 先找到security[i]前后满足条件的长度, 再和time比较
        int len = security.size();
        vector<int> leftLen(len, 0);
        vector<int> rightLen(len, 0);
        leftLen[0] = 0;
        rightLen[len-1] = 0;

        for(int i = 1; i < len; i++){
            if(security[i] <= security[i-1])
                leftLen[i] = leftLen[i-1] + 1;
            else
                leftLen[i] = 0;
        }

        for(int i = len-2; i >= 0; i--){
            if(security[i] <= security[i+1])
                rightLen[i] = rightLen[i+1] + 1;
            else
                rightLen[i] = 0;
        }

        vector<int> ans;
        for(int i = 0; i < len; i++){
            if(leftLen[i] >= time && rightLen[i] >= time)
                ans.push_back(i);
        }

        return ans;
    }
};