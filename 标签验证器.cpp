class Solution {
public:
    // 栈就行 很简单
    bool isValid(string code) {
        stack<string> mys;
        short state = 0; // 0表示什么都没有 1表示是CONTENT 2表示是CDATA
        int index = 0;
        while(index < code.length()){
            if(state == 0){ // 一定要是TAG
                if(code[index] != '<')
                    return false;

                int curIndex = index+1;
                string newTag;
                while(curIndex < code.length() && code[curIndex] != '>'){
                    if(code[curIndex] < 'A' || code[curIndex] > 'Z'){ // 仅包含大写字母
                        return false;
                    }
                    newTag.append(code[curIndex], 1);
                    curIndex++;
                    if(curIndex - index > 10){ // 长度范围1-9
                        return false;
                    }
                }

                if(curIndex == code.length())
                    return false;

                if(curIndex - index <= 1){ // 长度范围1-9
                    return false;
                }

                mys.push(newTag);
                index = curIndex + 1;
                state = 1;
            }
            else if(state == 1){ // 判断是否到结束TAG或新TAG开头或cdata开头
                if(code[index] == '<'){
                    bool curState = 0; // 0是结束TAG 1是新TAG
                    if(index+1 == code.length())
                        return false;

                    if(code[index+1] == '/'){
                        index++;
                        curState = 0;
                    }
                    else if(code[index+1] == '!'){
                        if(code.substr(index+1, 8) != "![CDATA[")
                            return false;

                        index += 9;
                        state = 2;
                        continue; // 不用读内容
                    }
                    else
                        curState = 1;


                    int curIndex = index+1;
                    string newTag;
                    while(curIndex < code.length() && code[curIndex] != '>'){
                        if(code[curIndex] < 'A' || code[curIndex] > 'Z'){ // 仅包含大写字母
                            return false;
                        }
                        newTag.append(code[curIndex], 1);
                        curIndex++;
                        if(curIndex - index > 10){ // 长度范围1-9
                            return false;
                        }
                    }

                    if(curIndex == code.length())
                        return false;

                    if(curIndex - index <= 1) // 长度范围1-9
                        return false;

                    if(curState == 0){
                        if(mys.empty())
                            return false;

                        if(mys.top() != newTag)
                            return false;

                        mys.pop();

                        if(mys.empty()){
                            if(curIndex + 1 != code.length())
                                return false;
                            else
                                return true;
                        }
                    }
                    else{
                        mys.push(newTag);
                    }

                    index = curIndex + 1;
                }

                else{
                    index++;
                }
            }
            else{ // 判断是否到cdata结束
                if(code[index] != ']')
                    index++;
                else{
                    if(code.substr(index, 3) == "]]>"){ // 结束了
                        index += 3;
                        state = 1;
                    }
                    else
                        index++;
                }
            }
        }

        if(state != 0)
            return false;

        return true;
    }
};