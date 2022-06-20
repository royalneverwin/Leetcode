class Solution {
public:
    string defangIPaddr(string address) {
        for(int i = 0; i < address.length(); i++) {
            if(address[i] == '.') {
                address.insert(i+1, "]");
                address.insert(i, "[");
                i = i + 1;
            }

        }
        return address;
    }
};