//无脑循环就vans

class Solution {
public:
    string intToRoman(int num) {
        map<int, char> mmap;
        mmap[1] = 'I';
        mmap[5] = 'V';
        mmap[10] = 'X';
        mmap[50] = 'L';
        mmap[100] = 'C';
        mmap[500] = 'D';
        mmap[1000] = 'M';
        string ans = "";
        while(num != 0){
            if(num >= 1000){
                ans.append(1, mmap[1000]);
                num -= 1000;
            }
            else if(num >= 900){
                ans.append(1, mmap[100]);
                ans.append(1, mmap[1000]);
                num -= 900;
            }
            else if(num >= 500){
                ans.append(1, mmap[500]);
                num -= 500;
            }
            else if(num >= 400){
                ans.append(1, mmap[100]);
                ans.append(1, mmap[500]);
                num -= 400;
            }
            else if(num >= 100){
                ans.append(1, mmap[100]);
                num -= 100;
            }
            else if(num >= 90){
                ans.append(1, mmap[10]);
                ans.append(1, mmap[100]);
                num -= 90;
            }
            else if(num >= 50){
                ans.append(1, mmap[50]);
                num -= 50;
            }
            else if(num >= 40){
                ans.append(1, mmap[10]);
                ans.append(1, mmap[50]);
                num -= 40;
            }
            else if(num >= 10){
                ans.append(1, mmap[10]);
                num -= 10;
            }
            else if(num == 9){
                ans.append("IX");
                num -= 9;
            }
            else if(num >= 5){
                ans.append(1, mmap[5]);
                num -= 5;
            }
            else if(num == 4){
                ans.append("IV");
                num -= 4;
            }
            else{
                ans.append(1, mmap[1]);
                num -= 1;
            }
        }
        return ans;
    }
};