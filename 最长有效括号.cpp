// 普通算法
// 无限debug
// 系统推荐动归
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        int index = 0;
        int length = s.length();
        int ans = 0;
        int cnt = 0;
        int indexAdd = 0;
        int left = 0;
        bool flag = false; // we only need to add index to avoid '(' before the first match
        while(index != length){
            int tmp = index;
            cnt = 0;
            indexAdd = 0;
            left = 0;
            flag = false;
            while(tmp != length){
                if(s[tmp] == '('){
                    st.push('(');
                    tmp++;
                    if(!flag)
                        indexAdd++;
                    else
                        left++;
                }
                else if(s[tmp] == ')'){
                    if(st.empty()){ // ')' exceeds
                        ans = max(ans, cnt);
                        index = tmp + 1;
                        break;
                    }
                    else{
                        st.pop();
                        if(!flag){
                            indexAdd--;
                            flag = true;
                        }
                        else{
                            if(left > 0)
                                left--;
                            else
                                indexAdd--;
                        }
                        cnt += 2;
                        tmp++;
                        // don't let '(' added latter effect our index change if '(' exceeds
                        if(st.empty()){
                            // right now we record the length
                            ans = max(ans, cnt);
                            index = tmp;
                            flag = true;
                        }
                    }
                }
            }
            if(tmp == length && !st.empty()){ // '(' exceeds, we forbid it
                index = index + indexAdd;
            }
            else if(tmp == length){ //finish calculate
                ans = max(ans, cnt);
                break;
            }
            while(!st.empty()) //clear st
                st.pop();
        }
        return ans;
    }
};