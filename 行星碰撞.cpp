class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++) {
            while(!st.empty() && (st.top() > 0 && asteroids[i] < 0)) {
                if(abs(st.top()) >= abs(asteroids[i])) {
                    break;
                }
                st.pop();
            }
            if(st.empty()) {
                st.push(asteroids[i]);
            }
            else if((st.top() > 0 && asteroids[i] > 0) || (st.top() < 0 && asteroids[i] < 0)
                    || (st.top() < 0 && asteroids[i] > 0)) {
                st.push(asteroids[i]);
            }
            else if(st.top() + asteroids[i] == 0) {
                st.pop();
            }
        }
        vector<int> ans(st.size(), 0);
        for(int i = ans.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};