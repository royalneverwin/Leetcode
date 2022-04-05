class Solution {
public:
#define LEFT 200001
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // 一定要先排序
        int slow = 0, fast = 0;
        int cnt = 0; // 记录找到了几对
        for(; slow < arr.size(); slow++){
            fast = max(fast, slow + 1);
            if(arr[slow] == LEFT)
                continue;
            else if(arr[slow] < 0){ // 要考虑 < 0的情况
                if(arr[slow] % 2 != 0) // 奇数肯定不对
                    return false;
                while(fast < arr.size() && arr[fast] < arr[slow]/2)
                    fast++;
                if(fast == arr.size())
                    return false;
                else if(arr[fast] > arr[slow]/2){
                    return false;
                }
                else{
                    arr[fast] = LEFT;
                    fast++;
                    cnt++;
                    if(cnt == arr.size()/2)
                        break;
                }
            }
            else{
                while(fast < arr.size() && arr[fast] < 2 * arr[slow])
                    fast++;
                if(fast == arr.size()){
                    return false;
                }
                else if(arr[fast] > 2 * arr[slow]){
                    return false;
                }
                else{
                    arr[fast] = LEFT;
                    fast++;
                    cnt++;
                    if(cnt == arr.size()/2) // 找完了 就退出
                        break;
                }
            }
        }
        if(cnt < arr.size() / 2)
            return false;
        return true;
    }
};