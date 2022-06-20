class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> myqu;
        bool flag = false;
        for(int i = 0; i < arr.size(); i++) {
            if(flag) {
                myqu.push(arr[i]);
                arr[i] = 0;
                flag = false;
            }
            else {
                if(!myqu.empty()) {
                    int num = myqu.front();
                    myqu.pop();
                    myqu.push(arr[i]);
                    if(num == 0)
                        flag = true;
                    arr[i] = num;
                }
                else {
                    if(arr[i] == 0)
                        flag = true;
                }
            }
        }
    }
};