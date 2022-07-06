class Solution {
public:

    // 分治
    // 遍历ops 假设每个op是最后一个操作，求出所有结果（先求出op的left和right的所有结果，再结合）
    unordered_map<string, vector<int>> umap;

    vector<int> diffWaysToCompute(string expression) {
        if(umap.count(expression))
            return umap[expression];

        vector<char> ops;
        vector<int> ans;
        int begin = 0;
        int end = 0;
        while(end < expression.length()) {
            while(end < expression.length() && expression[end] >= '0' && expression[end] <= '9') {
                end++;
            }

            if(end != expression.length()) {
                vector<int> lefts = diffWaysToCompute(expression.substr(0, end));
                vector<int> rights = diffWaysToCompute(expression.substr(end+1));

                for(auto& i: lefts) {
                    for(auto& j: rights) {
                        if(expression[end] == '+')
                            ans.push_back(i + j);
                        else if(expression[end] == '-')
                            ans.push_back(i - j);
                        else
                            ans.push_back(i * j);
                    }
                }
            }

            end++;
            begin = end;
        }

        if(ans.size() == 0)
            ans.push_back(atoi(expression.c_str()));
        umap[expression] = ans;

        return ans;
    }
};