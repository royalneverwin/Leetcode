class Solution {
public:
    string validIPAddress(string queryIP) {
        int begin = 0;
        int end = 0;
        bool is6 = 0;
        int cnt = 0;
        while(end < queryIP.length()) {
            while(end < queryIP.length() && queryIP[end] != '.' && queryIP[end] != ':') {
                if(isalpha(queryIP[end])) {
                    if((queryIP[end] >= 'G' && queryIP[end] <= 'Z') || (queryIP[end] >= 'g' && queryIP[end] <= 'z'))
                        return "Neither";
                    is6 = true;
                }
                end++;
            }

            if(is6 && queryIP[end] == '.')
                return "Neither";
            if(!is6 && queryIP[end] == ':')
                is6 = true;

            string tmp = queryIP.substr(begin, end - begin);

            cnt++;
            if(!is6 && cnt > 4)
                return "Neither";

            if(!is6 && cnt == 4 && queryIP[end] == '.')
                return "Neither";

            if(cnt > 8)
                return "Neither";

            if(is6 && cnt == 8 && queryIP[end] == ':')
                return "Neither";

            cout << tmp << endl;
            if(is6) {
                if(tmp.length() == 0 || tmp.length() > 4)
                    return "Neither";
            }
            else {
                if(tmp.length() == 0)
                    return "Neither";

                if(tmp.length() > 1 && tmp[0] == '0') { // 有前导0
                    return "Neither";
                }

                int num = atoi(tmp.c_str());
                if(num < 0 || num > 255)
                    return "Neither";
            }

            begin = end + 1;
            end++;
        }
        if(is6 && cnt == 8) {
            return "IPv6";
        }
        else if(!is6 && cnt == 4) {
            return "IPv4";
        }

        return "Neither";

    }
};