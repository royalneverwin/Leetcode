class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m-1;
        int index2 = n-1;
        int index;

        if(n == 0)
            return;
        if(m == 0){
            for(int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        for(index = m+n-1; index >= 0; index--){
            if(nums1[index1] > nums2[index2]){
                nums1[index] = nums1[index1];
                index1--;
                if(index1 < 0)
                    break;
            }
            else{
                nums1[index] = nums2[index2];
                index2--;
                if(index2 < 0)
                    break;
            }
        }

        index--;
        while(index2 >= 0){
            nums1[index] = nums2[index2];
            index2--;
            index--;
        }
    }
};