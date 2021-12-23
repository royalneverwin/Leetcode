class Solution {
public:
    bool ifLeap(int year){
        if(year % 100 == 0 && year % 400 == 0){
            return true;
        }
        else if(year % 4 == 0)
            return true;
        else
            return false;
    }
    int dayOfYear(string date) {
        // int index1 = date.find('-');
        // int index2 = date.find('-', index1+1);
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        int ans = 0;
        for(int i = 1; i < month; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10){
                ans += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11){
                ans += 30;
            }
            else{
                if(ifLeap(year))
                    ans += 29;
                else
                    ans += 28;
            }
        }
        return ans + day;
    }
};