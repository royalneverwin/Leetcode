class Solution {
public:
    string getAns(stack<string>& st){
        string cur;
        if(!st.empty()){
            cur = st.top();
            st.pop();
        }
        else{
            return "";
        }
        string tmp = getAns(st);
        tmp.append("/" + cur);
        return tmp;
    }

    string simplifyPath(string path) {
        stack<string> st;
        int index1 = 0;
        int index2 = 0;
        int length = path.length();
        while(1){
            while(index1 < length && path[index1] == '/')
                index1++;
            if(index1 == length) // 到头了
                break;
            index2 = index1 + 1;
            while(index2 < length && path[index2] != '/')
                index2++;
            string tmp = path.substr(index1, index2 - index1);
            if(tmp == ".."){
                if(!st.empty())
                    st.pop();
            }
            else if(tmp != "."){
                st.push(tmp);
            }
            if(index2 == length) // 到头了
                break;
            index1 = index2 + 1;
        }
        string ans = getAns(st);
        if(ans == "")
            ans = "/";
        return ans;
    }
};