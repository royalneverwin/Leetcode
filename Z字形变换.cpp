/*将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/zigzag-conversion
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int length = s.length();
        int row = 0, col = 0;
        int ifUp = 0;//if 1, row go up; else row go down
        char Zarray[numRows][length];
        memset(Zarray, '0', numRows*length*sizeof(char));
        for(int i = 0; i < length; i++){
            Zarray[row][col] = s[i];
            /*先给出row移动状态的更新*/
            if(row == numRows - 1){
                ifUp = 1;
            }
            if(row == 0){
                ifUp = 0;
            }
            if(ifUp){
                row -= 1;
                col += 1;
            }
            else{
                row += 1;
            }
        }
        string *ans;
        ans = new string;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < length; j++){
                if(Zarray[i][j] != '0'){
                    (*ans).append(1, Zarray[i][j]);
                }
            }
        }
        return *ans;
    }
};