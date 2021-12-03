class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> mmap;
        for(int i = 0; i < p.length(); i++){
            if(mmap.count(p[i]))
                mmap[p[i]]++;
            else
                mmap[p[i]] = 1;
        }
        vector<int> ans;
        //注意s.length()和p.length()都是uint！
        map<char, int> tmp = mmap;
        int left = 0;
        int right = 0;
        int maxLeft = s.length() - p.length();
        while(left <= maxLeft){ //剪枝1
            if(tmp.count(s[left]) && tmp[s[left]] != 0){ // match the first one
                right = left;
                while(right - left < p.length()){
                    if(!tmp.count(s[right])){
                        // no match, then <= right must not have the ans
                        left = right + 1;
                        tmp = mmap; // renew tmp
                        break;
                    }
                    else if(tmp.count(s[right]) && tmp[s[right]] == 0){
                        // have, but more than what we need
                        // change left, but don't need to change right
                        while(s[left] != s[right]){
                            tmp[s[left]]++;
                            left++;
                        }
                        tmp[s[left]]++;
                        left++; //i satisfies the first index s[i] = s[right],  left = i + 1
                    }
                    else{
                        tmp[s[right]]--;
                        right++;
                    }
                    if(right - left == p.length()){ //滑动窗口！这里不退出，而是移动窗口，看看下一个是否符合
                        ans.push_back(left);
                        tmp[s[left]]++;
                        left++;
                    }
                }
            }
            else{
                left++;
            }
        }
        return ans;
    }
};