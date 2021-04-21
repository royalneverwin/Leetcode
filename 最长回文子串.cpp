/*给你一个字符串 s，找到 s 中最长的回文子串。*/


class Solution {
public:
/*中心扩散法，时间复杂度O(n^2)
注意子串中心可能是点，可能是空隙*/
    string longestPalindrome(string s) {
        int length = s.length();
        int maxLength = 0;
        int tmpLength;
        int middle;
        int begin;
        int radius;
        /*先寻找中心在点上的回文子串*/
        for(int i = 0; i < length; i++){
            middle = i;
            tmpLength = 1;
            for(radius = 1; radius <= middle; radius++){
                if(middle + radius == length){
                    break;
                }
                if(s[middle - radius] == s[middle + radius]){
                    tmpLength += 2;
                }
                else{
                    break;
                }
            }
            if(tmpLength > maxLength){
                maxLength = tmpLength;
                begin = middle - radius + 1;
            }
        }
        /*再寻找中心在空隙中的回文子串*/
        for(int i = 0; i < length-1; i++){
            tmpLength = 0;
            for(radius = 0; radius <= i; radius++){
                if(i + 1 + radius == length){
                    break;
                }
                if(s[i-radius] == s[i+1+radius]){
                    tmpLength += 2;
                }
                else{
                    break;
                }
            }
            if(tmpLength > maxLength){
                maxLength = tmpLength;
                begin = i - radius + 1;
            }
        }
        return s.substr(begin, maxLength);
    }
};