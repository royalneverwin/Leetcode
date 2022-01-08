class Solution {
public:

    bool leap(int year){
        if(year % 100 == 0 && year % 400 == 0)
            return true;
        else if(year % 100 != 0 && year % 4 == 0)
            return true;
        return false;
    }

    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        int cnt = 0;
        for(int i = 1971; i < year; i++){
            if(leap(i))
                cnt += 366;
            else
                cnt += 365;
        }
        for(int i = 1; i < month; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
                cnt += 31;
            else if(i == 4 || i == 6 || i == 9 || i == 11)
                cnt += 30;
            else if(leap(year))
                cnt += 29;
            else
                cnt += 28;
        }
        cnt += day - 1;
        return days[cnt % 7];
    }
};