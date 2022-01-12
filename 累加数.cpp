class Solution {
public:
    // 大整数加法
    bool AddMatch(string& num, int index1, int index2, int index3, int index4){
        string num1 = num.substr(index1, index2 - index1);
        string num2 = num.substr(index2, index3 - index2);
        string num3 = num.substr(index3, index4 - index3);
        int length1 = index2 - index1;
        int length2 = index3 - index2;
        int length3 = index4 - index3;
        int tag1 = length1 - 1;
        int tag2 = length2 - 1;
        int tag3 = length3 - 1;
        bool carry = false;
        while(1){
            int tmp = num1[tag1] - '0' + num2[tag2] - '0' + carry;
            carry = false;
            if(tmp >= 10){ // 进位
                carry = true;
                tmp -= 10;
            }
            if(tmp != num3[tag3] - '0')
                return false;

            if(tag1 == 0 || tag2 == 0)
                break;
            else{
                tag1--;
                tag2--;
                tag3--;
            }

        }
        if(tag1 != 0){
            tag1--;
            tag3--;
            while(1){
                int tmp = num1[tag1] - '0' + carry;
                carry = false;
                if(tmp >= 10){
                    carry = true;
                    tmp -= 10;
                }
                if(tmp != num3[tag3] - '0')
                    return false;
                if(tag1 == 0)
                    break;
                else{
                    tag1--;
                    tag3--;
                }
            }
        }
        else if(tag2 != 0){
            tag2--;
            tag3--;
            while(1){
                int tmp = num2[tag2] - '0' + carry;
                carry = false;
                if(tmp >= 10){
                    carry = true;
                    tmp -= 10;
                }
                if(tmp != num3[tag3] - '0')
                    return false;
                if(tag2 == 0)
                    break;
                else{
                    tag2--;
                    tag3--;
                }
            }
        }
        // 算完了
        if(carry && (tag3 == 0 || num3[tag3-1] != '1'))
            return false;
        else
            return true;
    }

    // 回溯
    bool isSubAdditiveNumber(string& num, int index1, int index2, int index3){
        int length = num.size();
        int index4;
        // i, j是第一个数字、第二个数字长度, 则第三个长度为max或max+1
        // 前两个不可能为0, 这里要特判一下, 因为主函数调用sub时会考虑到
        // num[index3] == '0', 但sub函数调用sub时不会考虑到num[index3]
        if(num[index3] == '0'){
            return false;
        }
        int k = max(index2 - index1, index3 - index2);

        // 若第三个长度是max
        index4 = index3 + k;
        if(index4 > length)
            return false;
        if(AddMatch(num, index1, index2, index3, index4)){
            if(index4 == length) // 结束了
                return true;
            else if(isSubAdditiveNumber(num, index2, index3, index4))
                return true;
        }

        // 若第三个长度是max+1
        index4 = index3 + k + 1;
        if(index4 > length) // 结束寻找j, 因为j增大, k一定不会变小
            return false;
        if(AddMatch(num, index1, index2, index3, index4)){
            if(index4 == length) // 结束了
                return true;
            else if(isSubAdditiveNumber(num, index2, index3, index4))
                return true;
        }

        return false;
    }
    bool isAdditiveNumber(string num) {
        int length = num.length();
        if(length < 3) // 至少三个数
            return false;
        int index1 = 0;
        int index2, index3, index4;
        // preprocess 如果有0的情况
        if(num[0] == '0'){ // 第一个数是0
            if(num[1] == '0'){ //第二个数也是0
                for(int i = 2; i < length; i++){ // 应该全是0
                    if(num[i] != '0')
                        return false;
                }
                return true;
            }
            else{ // 第二个数不是0
                for(int j = 1; j <= length / 2; j++){
                    if(index1 + 1 + j == length)
                        break;
                    if(num[index1 + 1 + j] == '0') //第三个数是0, 肯定不对
                        continue;
                    index2 = index1 + 1;
                    index3 = index2 + j;
                    if(isSubAdditiveNumber(num, index1, index2, index3))
                        return true;
                }
            }
        }
        else{
            for(int i = 1; i <= length / 2; i++){ // 第一个数不是0
                if(num[index1 + i] == '0'){ // 第二个数是0
                    if(num[index1 + i + 1] == '0') // 第三个数是0, 肯定不对
                        continue;
                    index2 = index1 + i;
                    index3 = index2 + 1;
                    if(isSubAdditiveNumber(num, index1, index2, index3))
                        return true;
                }
                else{ // 第二个数也不是0
                    for(int j = 1; j <= length / 2; j++){
                        if(index1 + i + j == length) // 超范围, 结束寻找j, 因为j还会增大
                            break;
                        if(num[index1 + i + j] == '0') // 第三个数是0, 肯定不对
                            continue;
                        index2 = index1 + i;
                        index3 = index2 + j;
                        if(isSubAdditiveNumber(num, index1, index2, index3))
                            return true;
                    }
                }
            }
        }
        return false;
    }
};