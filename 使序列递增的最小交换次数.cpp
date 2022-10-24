class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size();
        vector<vector<int>> dp(l, vector<int>(2, 0)); // dp[idx][1] 表示交换nums1和nums2的idx位次数 0表示不交换。值为-1表示不成立
        // 边界
        dp[l-1][0] = 0;
        dp[l-1][1] = 1;
        for(int i = l-2; i >= 0; i--) {
            if(nums1[i] < nums1[i+1] && nums1[i] < nums2[i+1]) {
                if(nums2[i] < nums1[i+1] && nums2[i] < nums2[i+1]) { // 随便选
                    if(dp[i+1][0] == -1) {
                        dp[i][0] = dp[i+1][1];
                        dp[i][1] = dp[i+1][1]+1;
                    }
                    else if(dp[i+1][1] == -1) {
                        dp[i][0] = dp[i+1][0];
                        dp[i][1] = dp[i+1][0]+1;
                    }
                    else {
                        dp[i][0] = min(dp[i+1][0], dp[i+1][1]);
                        dp[i][1] = min(dp[i+1][0], dp[i+1][1])+1;
                    }
                }
                else if(nums2[i] < nums1[i+1]) { // 父交换或子交换
                    if(dp[i+1][0] == -1) {
                        dp[i][0] = dp[i+1][1];
                        dp[i][1] = -1;
                    }
                    else if(dp[i+1][1] == -1) {
                        dp[i][0] = -1;
                        dp[i][1] = dp[i+1][0]+1;
                    }
                    else {
                        dp[i][0] = dp[i+1][1];
                        dp[i][1] = dp[i+1][0]+1;
                    }
                }
                else if(nums2[i] < nums2[i+1]) { // 父子都交换或都不交换
                    if(dp[i+1][0] == -1) {
                        dp[i][0] = -1;
                        dp[i][1] = dp[i+1][0]+1;
                    }
                    else if(dp[i+1][1] == -1) {
                        dp[i][0] = dp[i+1][1];
                        dp[i][1] = -1;
                    }
                    else {
                        dp[i][0] = dp[i+1][0];
                        dp[i][1] = dp[i+1][1]+1;
                    }
                }
                else {
                    // 用例保证不会存在这种
                    cout << "What the fuck" << endl;
                    exit(-1);
                }
            }
            else if(nums1[i] < nums1[i+1]) { // 父子都交换或都不交换
                if(dp[i+1][0] == -1) {
                    dp[i][0] = -1;
                    dp[i][1] = dp[i+1][0]+1;
                }
                else if(dp[i+1][1] == -1) {
                    dp[i][0] = dp[i+1][1];
                    dp[i][1] = -1;
                }
                else {
                    dp[i][0] = dp[i+1][0];
                    dp[i][1] = dp[i+1][1]+1;
                }
            }
            else if(nums1[i] < nums2[i+1]) { // 父交换或子交换
                if(dp[i+1][0] == -1) {
                    dp[i][0] = dp[i+1][1];
                    dp[i][1] = -1;
                }
                else if(dp[i+1][1] == -1) {
                    dp[i][0] = -1;
                    dp[i][1] = dp[i+1][0]+1;
                }
                else {
                    dp[i][0] = dp[i+1][1];
                    dp[i][1] = dp[i+1][0]+1;
                }
            }
            else {
                // 用例保证不会存在这种
                cout << "What the fuck" << endl;
                exit(-1);
            }
        }
        if(dp[0][0] == -1)
            return dp[0][1];
        else if(dp[0][1] == -1)
            return dp[0][0];
        else
            return min(dp[0][0], dp[0][1]);
    }
};