/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int end = 0;
        return FindInteger(s, 0, end);
    }

    NestedInteger FindInteger(string s, int start, int &endIndex) {
        if(start == s.length()) // 如果s为空 直接return
            return NestedInteger();

        if(s[start] == '['){ // 有SubInteger
            NestedInteger ans;
            int curStart = start + 1;
            endIndex = curStart;
            while(endIndex < s.length() && s[endIndex] != ']'){ // 遍历
                NestedInteger subInteger = FindInteger(s, curStart, endIndex);
                if(endIndex < s.length() && s[endIndex] == ',') // 到下一个数据
                    endIndex++;
                curStart = endIndex;
                ans.add(subInteger);
            }
            if(s[endIndex] == ']')
                endIndex++;

            return ans;
        }
        else{ // 就一个数
            while(endIndex < s.length() && (s[endIndex] >= '0' && s[endIndex] <= '9') || s[endIndex] == '-')
                endIndex++;
            int num = atoi(s.substr(start, endIndex - start).c_str());
            NestedInteger ret(num);
            return ret;
        }
    }

};