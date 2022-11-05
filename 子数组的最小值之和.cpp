class Solution {
public:
    // 单调栈
    // leftMax和rightMax
    // 经典题
    // 对于重复元素 我们选择边界条件左边要<= 右边要<
#define MOD (1000000000+7)
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) leftMax[i] = -1;
            else leftMax[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) rightMax[i] = n;
            else rightMax[i] = st.top();
            st.push(i);
        }
        long long res = 0;
        for(int i = 0; i < n; i++) {
            res = (res + long(i-leftMax[i])*long(rightMax[i]-i) * arr[i]) % MOD;
        }
        return res;
    }
};