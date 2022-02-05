class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for(; index < word.length(); index++)
            if(word[index] == ch)
                break;
        if(index == word.length())
            return word;
        else
            reverse(word.begin(), word.begin() + index + 1);
        return word;
    }
};