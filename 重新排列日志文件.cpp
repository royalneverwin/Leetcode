class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, map<string, int>> let;
        vector<int> dig;
        for(int i = 0; i < logs.size(); i++){
            int index = 0;
            while(logs[i][index] != ' ')
                index++;

            index++;
            if(logs[i][index] >= '0' && logs[i][index] <= '9')
                dig.push_back(i);

            else{
                string mark = logs[i].substr(0, index-1);
                string content = logs[i].substr(index, logs[i].length() - index);

                if(!let.count(content)){
                    map<string, int> tmp;
                    tmp[mark] = i;
                    let[content] = tmp;
                }
                else{
                    let[content][mark] = i;
                }
            }
        }



        vector<string> ans(logs.size(), "");
        int index = 0;
        for(auto& i: let){
            for(auto& j: i.second){
                ans[index] = logs[j.second];
                index++;
            }
        }

        for(int i = 0; i < dig.size(); i++){
            ans[index] = logs[dig[i]];
            index++;
        }

        return ans;
    }
};