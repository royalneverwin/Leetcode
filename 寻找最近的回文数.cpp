class Solution {
public:
    string Sub(string s1, string s2){ // s1 >= s2
        int index1 = s1.length()-1;
        int index2 = s2.length()-1;
        while(index2 >= 0){
            if(s1[index1] >= s2[index2])
                s1[index1] = s1[index1] - (s2[index2] - '0');
            else{
                s1[index1] = s1[index1] - (s2[index2] - '0') + 10;
                for(int i = index1-1; i >= 0; i--){
                    if(s1[i] != '0'){
                        s1[i]--;
                        break;
                    }
                    else{
                        s1[i] = '9';
                    }
                }
            }
            index1--;
            index2--;
        }
        int index = 0;
        for(; index < s1.length(); index++){
            if(s1[index] != '0')
                break;
        }
        return s1.substr(index, s1.length() - index);
    }

    int Cmp(const string&s1, const string&s2){ // 1->s1 < s2, 0 -> s1 == s2, -1 -> s1 > s2
        if(s1.length() < s2.length())
            return 1;
        else if(s1.length() > s2.length())
            return -1;
        else{
            if(s1 == s2)
                return 0;
            if(s1 < s2)
                return 1;
            else
                return -1;
        }
    }

    void ChangeToSmaller(string& s, int changeIndex, const string& n){
        // 特殊情况, n = 10000000类型, 所以我们需要构造9999999特判
        string special(n.length()-1, '9');
        int index = changeIndex;
        while(index >= 0){
            if(s[index] == '0')
                s[index] = '9';
            else{
                s[index]--;
                break;
            }
            index--;
        }
        // 不用特判 因为不可能减到index < 0, 但要处理ans2[0] = 0的情况
        if(s[0] == '0' && s.length() > 1)
            s = s.substr(1, s.length()-1);
        index = s.length() / 2;
        if(s.length() % 2 != 0) // 奇数特判
            index++;
        for(; index < s.length(); index++)
            s[index] = s[s.length() - index - 1];

        if(special == n) // 注意特判和n相同的情况
            return;
        if(Cmp(Sub(n, s), Sub(n, special)) == -1)
            s = special;
    }


    void ChangeToGreater(string& s, int changeIndex, const string& n){

        int index = changeIndex;
        while(index >= 0){
            s[index]++;
            if(s[index] == '9'+1)
                s[index] = '0';
            else
                break;
            index--;
        }
        if(index < 0){ // 有进位
            s.append(1, '0'); // 多了一位
            for(int i = changeIndex + 1; i > 0; i--){
                s[i+1] = s[i];
            }
            s[0] = '1';
        }
        index = s.length() / 2;
        if(s.length() % 2 != 0) // 奇数特判
            index++;
        for(; index < s.length(); index++)
            s[index] = s[s.length() - index - 1];
    }


    string nearestPalindromic(string n) {
        // 构造一个回文整数ans1, 和待定ans2
        string ans1(n.length(), '0');
        string ans2(n.length(), '0');
        int changeIndex; // 修改ans2需要改变的index
        int index = 0;
        string sub1, sub2;


        for(; index < n.length() / 2; index++){
            ans1[index] = n[index];
            ans2[index] = n[index];
        }
        changeIndex = index-1;
        if(n.length() % 2 != 0){ // 奇数长度
            ans1[index] = n[index];
            ans2[index] = n[index];
            changeIndex = index;
            index++;
        }
        for(; index < n.length(); index++){
            ans1[index] = ans1[n.length() - index - 1];
        }

        // 比较ans1和ans2哪个离n最近
        if(ans1 < n){ // 构造的ans1比n小, 那我们就让ans2 > n
            ChangeToGreater(ans2, changeIndex, n);
            sub1 = Sub(n, ans1);
            sub2 = Sub(ans2, n);
            int compare = Cmp(sub1, sub2);
            if(compare == 1)
                return ans1;

            else if(compare == -1)
                return ans2;
            else // 一样返回较小的那个
                return ans1;
        }

        else if(ans1 > n){ // 让ans2 < n
            ChangeToSmaller(ans2, changeIndex, n);
            sub1 = Sub(ans1, n);
            sub2 = Sub(n, ans2);
            int compare = Cmp(sub1, sub2);
            if(compare == 1)
                return ans1;

            else if(compare == -1)
                return ans2;
            else // 一样返回较小的那个
                return ans2;
        }

        else{ // 修改ans1和ans2, 分别 < n 和 > n
            ChangeToSmaller(ans1, changeIndex, n);
            ChangeToGreater(ans2, changeIndex, n);
            sub1 = Sub(n, ans1);
            sub2 = Sub(ans2, n);
            int compare = Cmp(sub1, sub2);
            if(compare == 1)
                return ans1;
            else if(compare == -1)
                return ans2;
            else
                return ans1;
        }
    }
};




// 法2 转化成long
class Solution {
public:

    string nearestPalindromic(string n) {
        // 构造一个回文整数ans1
        // 三种可能prefix, prefix+1, prefix-1
        // 特判1000001和99999999之间的变化
        long prefix;
        // 特殊判断：1000->99, 999->10001, 9999->100001的情况
        vector<long> ansArray = {static_cast<long>(pow(10, n.length()-1)) - 1,
                                 static_cast<long>(pow(10, n.length())) + 1};

        prefix = stol(n.substr(0, (n.length() + 1) / 2));
        for(auto &i: {prefix-1, prefix, prefix+1}){
            string tmp = to_string(i);
            string s =  tmp + string(tmp.rbegin() + (n.length() & 1), tmp.rend());
            ansArray.push_back(stol(s));
        }
        prefix = stol(n);
        long ans = ansArray[0];
        for(auto& i: ansArray){
            if(i != prefix && (abs(i - prefix) < abs(ans - prefix) || (abs(i-prefix) == abs(ans - prefix) && i < ans)))
                ans = i;
        }
        return to_string(ans);
    }
};