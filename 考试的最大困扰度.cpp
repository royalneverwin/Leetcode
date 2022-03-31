class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // 要么全改成T要么全改成F
        // 每个都试试
        int cnt = 0;
        int left = 0, right = 0;
        int ans = 0;
        // 先全改成T
        while(right < answerKey.length()){
            while(right < answerKey.length()){
                if(answerKey[right] == 'F')
                    cnt++;
                if(cnt > k) // 超过可以修改的界限
                    break;
                right++;
            }
            ans = max(ans, right - left);
            while(left < answerKey.length() && cnt > k){
                if(answerKey[left] == 'F') // 删去左边的
                    cnt--;
                left++;
            }
            right++; // right处可以修改了
        }
        left = right = 0;
        cnt = 0;
        // 再全改成F
        while(right < answerKey.length()){
            while(right < answerKey.length()){
                if(answerKey[right] == 'T')
                    cnt++;
                if(cnt > k)
                    break;
                right++;
            }
            ans = max(ans, right - left);
            while(left < answerKey.length() && cnt > k){
                if(answerKey[left] == 'T')
                    cnt--;
                left++;
            }
            right++;
        }
        return ans;
    }
};