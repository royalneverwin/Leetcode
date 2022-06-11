class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq_emails;
        for(size_t i = 0; i < emails.size(); i++) {
            int index = 0;
            while(index < emails[i].length() && emails[i][index] != '@') {
                index++;
            }
            string local = emails[i].substr(0, index);
            string pin = emails[i].substr(index+1, emails[i].length() - index - 1);
            int index2 = 0;
            while(index2 < local.length() && local[index2] != '+') {
                if(local[index2] == '.') {
                    local.erase(index2, 1);
                }
                else {
                    index2++;
                }
            }
            local = local.substr(0, index2);
            if(!uniq_emails.count(local + "@" + pin))
                uniq_emails.insert(local + "@" + pin);
        }
        return uniq_emails.size();
    }
};