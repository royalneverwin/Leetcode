class Solution {
public:
    string removeOuterParentheses(string s) {
stack<char> st;
st.push('(');pytype
int begin = 0;
int end = 1;
string ans;
while(end != s.length()) {
    if(s[end] == '(')
st.push('(');
    else
st.pop();
    if(st.empty()) {
ans += s.substr(begin + 1, end - begin - 1);
begin = end + 1;
    }
    end++;
}

return ans;

    }
};


