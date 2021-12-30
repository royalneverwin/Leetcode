class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if(num == 1){
            return false;
        }
        int i;
        sum += 1;
        for(i = 2; i < sqrt(num); i++){
            if(num % i == 0){
                sum += i;
                sum += num / i;
            }
        }
        if(i == sqrt(num))
            sum += i;
        if(sum == num)
            return true;
        return false;
    }
};