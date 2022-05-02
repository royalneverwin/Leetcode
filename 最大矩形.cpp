class Solution {
public:
    int maxRec(vector<int>& cnt){ // 用单调栈计算最大矩形面积
        vector<int> maxLeft(cnt.size(), 0); // 第一个比cnt[i]小的左边位置
        vector<int> maxRight(cnt.size(), 0); // 第一个比cnt[i]小的右边位置
        stack<int> mys;
        for(int i = 0; i < cnt.size(); i++){
            while(!mys.empty() && cnt[mys.top()] > cnt[i]){
                maxRight[mys.top()] = i;
                mys.pop();
            }

            mys.push(i);
        }

        while(!mys.empty()){
            maxRight[mys.top()] = cnt.size();
            mys.pop();
        }


        for(int i = cnt.size()-1; i >= 0; i--){
            while(!mys.empty() && cnt[mys.top()] > cnt[i]){
                maxLeft[mys.top()] = i;
                mys.pop();
            }

            mys.push(i);
        }

        while(!mys.empty()){
            maxLeft[mys.top()] = -1;
            mys.pop();
        }


        int ret = 0;
        for(int i = 0; i < cnt.size(); i++){
            ret = max(ret, cnt[i] * (maxRight[i] - maxLeft[i] - 1));
        }

        return ret;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> cnt(matrix.size(), vector<int>(matrix[0].size(), 0));
        // 从(i, j)往下的1的个数
        for(int j = matrix[0].size()-1; j >= 0; j--){
            for(int i = matrix.size()-1; i >= 0; i--){
                if(i == matrix.size()-1){
                    if(matrix[i][j] == '0'){
                        cnt[i][j] = 0;
                    }
                    else{
                        cnt[i][j] = 1;
                    }
                }
                else{
                    if(matrix[i][j] == '0'){
                        cnt[i][j] = 0;
                    }
                    else{
                        cnt[i][j] = cnt[i+1][j] + 1;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            ans = max(ans, maxRec(cnt[i]));
        }

        return ans;
    }
};