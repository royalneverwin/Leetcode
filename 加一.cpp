class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = 1;
        int index = digits.size()-1;
        while(index >= 0){
            if(flag){
                digits[index]++;
                flag = false;
            }
            if(digits[index] == 10){
                digits[index] = 0;
                flag = true;
                index--;
            }
            else{
                break;
            }
        }
        if(flag){
            digits.insert(digits.begin(), 1);
            return digits;
        }
        else{
            return digits;
        }
    }
};