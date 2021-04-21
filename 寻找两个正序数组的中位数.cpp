/*
 * 时间复杂度log(m+n)的做法
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
*/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*先对有空数组的情况特殊处理*/
        if(nums1.size() == 0){
            if(nums2.size() % 2 == 0)
                return double(nums2[nums2.size()/2] + nums2[nums2.size()/2-1])/2;
            else
                return nums2[nums2.size()/2];
        }
        else if(nums2.size() == 0){
            if(nums1.size() % 2 == 0)
                return double(nums1[nums1.size()/2] + nums1[nums1.size()/2-1])/2;
            else
                return nums1[nums1.size()/2];
        }
        size_t totalNum = nums1.size() + nums2.size();
        int start1 = 0, start2 = 0, end1 = nums1.size()-1, end2 = nums2.size()-1;
        if(totalNum % 2 == 0){//偶数
            int location = totalNum / 2 - 1;
            /*compare1, compare2都是数组相对start的位置，不是绝对位置*/
            int compare1;
            int compare2;
            while(location != 0){
                compare1 = min(location/2, end1 - start1);
                compare2 = min(location/2, end2 - start2);
                /*如果其中一个数组只剩一个元素，进行特殊处理，可以直接找到答案*/
                if(start1 == end1){
                    if(nums1[start1] <= nums2[start2 + location-1]){
                        return double(nums2[start2 + location-1] + nums2[start2 +location])/2;
                    }
                    else{
                        if(nums1[start1] <= nums2[start2 + location])
                            return double(nums2[start2+location] + nums1[start1])/2;
                        else{
                            if(nums1[start1] <= nums2[start2+location+1])
                                return double(nums2[start2+location] + nums1[start1])/2;
                            else
                                return double(nums2[start2+location] + nums2[start2+location+1])/2;
                        }
                    }
                }
                if(start2 == end2){
                    if(nums2[start2] <= nums1[start1+location-1]){
                        return double(nums1[start1+location-1] + nums1[start1+location])/2;
                    }
                    else{
                        if(nums2[start2] <= nums1[start1+location])
                            return double(nums1[start1+location] + nums2[start2])/2;
                        else{
                            if(nums2[start2] <= nums1[start1+location+1])
                                return double(nums1[start1+location] + nums2[start2])/2;
                            else
                                return double(nums1[start1+location] + nums1[start1+location+1])/2;
                        }
                    }
                }
                /*否则*/
                if(nums1[start1+compare1] <= nums2[start2+compare2]){
                    if(location % 2 != 0){
                        location -= compare1 + 1;
                        start1 += compare1 + 1;
                        if(start1 > end1){
                            return double(nums2[start2+location] + nums2[start2+location+1])/2;
                        }
                    }
                    else{
                        location -= compare1;
                        start1 += compare1;
                    }
                }
                else{
                    if(location % 2 != 0){
                        location -= compare2 + 1;
                        start2 += compare2 + 1;
                        if(start2 > end2){
                            return double(nums1[start1+location] + nums1[start1+location+1])/2;
                        }
                    }
                    else{
                        location -= compare2;
                        start2 += compare2;
                    }
                }
            }
            /*location = 0, 需要第一个元素*/
            if(nums1[start1] <= nums2[start2]){
                if(start1 == end1)//nums1只有一个元素了
                    return double(nums1[start1] + nums2[start2])/2;
                if(nums1[start1+1] <= nums2[start2])
                    return double(nums1[start1] + nums1[start1+1])/2;
                else
                    return double(nums1[start1] + nums2[start2])/2;
            }
            else
            if(start2 == end2)
                return double(nums1[start1] + nums2[start2])/2;
            if(nums2[start2+1] <= nums1[start1])
                return double(nums2[start2] + nums2[start2+1])/2;
            else
                return double(nums1[start1] + nums2[start2])/2;
        }
        else{//奇数
            int location = totalNum / 2;
            /*compare1, compare2都是数组相对start的位置，不是绝对位置*/
            int compare1;
            int compare2;
            while(location != 0){
                compare1 = min(location/2, end1 - start1);
                compare2 = min(location/2, end2 - start2);
                /*如果一个数组只剩一个元素，进行特殊处理，可以直接找到答案*/
                if(start1 == end1){
                    if(nums1[start1] <= nums2[start2+location-1]){
                        return nums2[start2+location-1];
                    }
                    else{
                        if(nums1[start1] <= nums2[start2+location])
                            return nums1[start1];
                        else
                            return nums2[start2+location];
                    }
                }
                if(start2 == end2){
                    if(nums2[start2] <= nums1[start1+location-1]){
                        return nums1[start1+location-1];
                    }
                    else{
                        if(nums2[start2] <= nums1[start1+location])
                            return nums2[start2];
                        else
                            return nums1[start1+location];
                    }
                }
                /*否则*/
                if(nums1[start1+compare1] <= nums2[start2+compare2]){
                    if(location % 2 != 0){
                        location -= compare1 + 1;
                        start1 += compare1 + 1;
                        if(start1 > end1){//nums1元素全部被淘汰，可直接得结果
                            return nums2[start2+location];
                        }
                    }
                    else{
                        location -= compare1;
                        start1 += compare1;
                    }
                }
                else{
                    if(location % 2 != 0){
                        location -= compare2 + 1;
                        start2 += compare2 + 1;
                        if(start2 > end2){//nums2元素全部被淘汰，可直接得结果
                            return nums1[start1+location];
                        }
                    }
                    else{
                        location -= compare2;
                        start2 += compare2;
                    }
                }
            }
            /*location = 0, 需要第一个元素*/
            if(nums1[start1] <= nums2[start2])
                return nums1[start1];
            else
                return nums2[start2];
        }
    }
};