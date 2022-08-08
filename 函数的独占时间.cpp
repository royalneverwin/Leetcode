class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;
        stack<int> subSt;
        vector<int> ans(n, 0);
        for(auto& log: logs) {
            // read info
            int idx1 = 0, idx2 = 0;
            while(log[idx2] != ':')
                idx2++;
            int id = atoi(log.substr(idx1, idx2).c_str());
            idx1 = idx2+1;
            idx2 = idx1;
            while(log[idx2] != ':')
                idx2++;
            string op = log.substr(idx1, idx2 - idx1);
            idx1 = idx2+1;
            int timestamp = atoi(log.substr(idx1).c_str());

            // renew process
            if(op == "start") {
                st.push(make_pair(id, timestamp));
                subSt.push(0);
            }
            else { // end
                pair<int, int> tmp = st.top();
                st.pop();
                int sub = subSt.top();
                subSt.pop();
                if(tmp.first != id) {
                    cout << "wrong" << endl;
                    exit(1);
                }
                ans[id] += timestamp - tmp.second + 1 - sub;
                // renew subSt
                if(!subSt.empty()) {
                    int nxt = subSt.top();
                    subSt.pop();
                    subSt.push(nxt + timestamp - tmp.second + 1);
                }
            }
        }
        return ans;
    }
};