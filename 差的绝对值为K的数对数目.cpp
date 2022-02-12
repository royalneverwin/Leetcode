class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int length = nums.size();
        int ans = 0;
        for(int i = 0; i < length - 1; i++){
            for(int j = i + 1; j < length; j++){
                if(abs(nums[i] - nums[j]) == k)
                    ans++;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        int length = nums.size();
        map<int, int> mmap;
        for(int i = 0; i < length; i++){
            if(mmap.find(nums[i]) == mmap.end())
                mmap[nums[i]] = 1;
            else
                mmap[nums[i]]++;
        }

        auto index1 = mmap.begin();
        auto index2 = mmap.begin();
        int ans = 0;

        for(; index1 != mmap.end(); index1++){
            while(1){
                if(index2 == mmap.end())
                    break;
                else if(index2->first - index1->first < k)
                    index2++;
                else
                    break;
            }
            if(index2 == mmap.end())
                break;
            if(index2->first - index1->first == k)
                ans += index1->second * index2->second;
        }

        return ans;
    }
};