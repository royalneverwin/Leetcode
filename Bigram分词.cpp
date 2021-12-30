class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        int index1 = 0;
        int index2 = text.find(' ', 0);
        bool flag1 = false;
        bool flag2 = false;
        vector<string> ans;
        while(index2 != text.npos){
            // 一定要注意if else条件的顺序，不同的顺序会有不同的结果！
            // flag1 == true && flag2 == true放第一，防止third的词和第一个或第二个重复
            // flag1 == true && substr == second放第二，防止second和first重复
            // substr == first放第三
            // 都不符合记得重置flag1和flag2
            if(flag1 == true && flag2 == true){
                ans.push_back(text.substr(index1, index2 - index1));
                flag1 = false;
                flag2 = false;
                if(text.substr(index1, index2 - index1) == first){
                    if(first == second)
                        flag2 = true;
                    flag1 = true;
                }
            }
            else if(flag1 == true && text.substr(index1, index2 - index1) == second){
                flag2 = true;
            }
            else if(text.substr(index1, index2 - index1) == first){
                flag1 = true;
            }
            else{ // 重置
                flag1 = false;
                flag2 = false;
            }
            index1 = index2 + 1;
            index2 = text.find(' ', index1);
        }
        if(flag1 == true && flag2 == true){
            ans.push_back(text.substr(index1, text.length() - index1));
        }
        return ans;
    }
};