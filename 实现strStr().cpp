//KMP算法

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0; //这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符
        //KMP算法
        int next[50010];
        next[0] = -1; //便于后面求next处理
        next[1] = 0;
        for(int i = 2; i < needle.length(); i++){
            if(needle[i-1] == needle[next[i-1]]){
                next[i] = next[i-1] + 1;
            }
            else{
                int k = next[i-1];
                while(k != -1 && needle[i-1] != needle[k]){
                    k = next[k];
                }
                next[i] = k + 1;
            }
        }
        int xIndex = 0;
        int yIndex = 0;
        while(yIndex != needle.length() && xIndex != haystack.length()){
            if(needle[yIndex] == haystack[xIndex]){
                xIndex++;
                yIndex++;
            }
            else{
                yIndex = next[yIndex];
                if(yIndex == -1){
                    xIndex++;
                    yIndex++;
                }
            }
        }
        if(yIndex == needle.length()){
            return xIndex - needle.length();
        }
        else{
            return -1;
        }
    }
};