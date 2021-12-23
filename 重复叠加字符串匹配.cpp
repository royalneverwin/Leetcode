class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string tmp = "";
        int lengtha = a.length();
        int lengthb = b.length();
        int length = 0;
        if(lengthb == 0)
            return 0;
        int time = lengthb / lengtha;
        if(lengthb % lengtha != 0)
            time++;
        time++;
        for(int i = 0; i < time; i++)
            tmp += a;
        length = lengtha * time;
        // length >= lengthb + lengtha
        int index = tmp.find(b);
        if(index != tmp.npos){
            if(index + lengthb <= length - lengtha) // add one more a
                return length / lengtha - 1;
            else // just fit
                return length / lengtha;
        }
        else // not match
            return -1;
    }
};