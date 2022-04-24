class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        int begin = 0, end = 0;
        int cnt = 1;
        string tmp;
        while(end < sentence.length()){
            while(end < sentence.length() && sentence[end] != ' '){
                end++;
            }

            char tmpc = tolower(sentence[begin]);
            if(tmpc == 'a' || tmpc == 'e' || tmpc == 'i'
               || tmpc == 'o' || tmpc == 'u'){
                tmp = sentence.substr(begin, end-begin) + "ma" + string(cnt, 'a');

            }
            else{
                tmp = sentence.substr(begin+1, end-begin-1) + string(1, sentence[begin]) + "ma" + string(cnt, 'a');
            }


            if(cnt != 1)
                ans.append(1, ' ');

            ans.append(tmp);
            cnt++;
            begin = end+1;
            end = begin;
        }

        return ans;

    }
};