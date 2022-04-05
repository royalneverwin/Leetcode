class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size()-1;
        if(letters[right] <= target) // 特判
            return letters[left];
        // 二分
        return *upper_bound(letters.begin(), letters.end(), target);

    }
};