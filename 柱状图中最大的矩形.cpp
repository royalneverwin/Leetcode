class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调栈
        int l = heights.size();
        stack<int> st;
        vector<int> rightMax(l, 0); // 右边第一个比它小的
        vector<int> leftMax(l, 0); // 左边第一个比它小的
        for(int i = 0; i < l; i++){ // 单调栈求rightMax
            if(st.empty() || heights[st.top()] <= heights[i])
                st.push(i);
            else{
                while(!st.empty() && heights[st.top()] > heights[i]){
                    rightMax[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            rightMax[st.top()] = l;
            st.pop();
        }

        for(int i = l-1; i >= 0; i--){ // 单调栈求leftMax
            if(st.empty() || heights[st.top()] <= heights[i])
                st.push(i);
            else{
                while(!st.empty() && heights[st.top()] > heights[i]){
                    leftMax[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            leftMax[st.top()] = -1;
            st.pop();
        }

        int ans = 0;
        for(int i = 0; i < l; i++){
            ans = max(ans, (rightMax[i] - leftMax[i] - 1) * heights[i]);
        }

        return ans;
    }
};