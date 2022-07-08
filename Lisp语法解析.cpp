class Solution {
public:
    struct table {
        unordered_map<string, int> idents;
        struct table *prev;
        struct table *next;
    };
    typedef struct table identTable;

    int evaluateSubExp(string expression, int begin, int length, identTable *cur) {
        if(cur == nullptr) {
            cur = new identTable;
            cur->prev = nullptr;
            cur->next = nullptr;
        }
        else {
            identTable *tmp = new identTable;
            cur->next = tmp;
            tmp->prev = cur;
            tmp->next = nullptr;
            cur = tmp;
        }

        int idx1 = 1, idx2 = 1; // 开头是(, 忽略
        while(idx2 < expression.length() && expression[idx2] != ' ') {
            idx2++;
        }
        string op = expression.substr(idx1, idx2 - idx1);
        if(op == "let") {
            while(expression[idx2] != ')') { // 判断是一组v和e还是e
                idx1 = idx2 + 1;
                idx2 = idx1;
                if(expression[idx1] == '(') { // e
                    int blockCnt = 1;
                    while(blockCnt != 0) {
                        idx2++;
                        if(expression[idx2] == '(')
                            blockCnt++;
                        if(expression[idx2] == ')')
                            blockCnt--;
                    }
                    // idx2 在右括号
                    idx2++; // 在空格

                    // 这就是结果
                    return evaluateSubExp(expression.substr(idx1, idx2 - idx1), idx1, idx2 - idx1, cur);
                }
                else { // 一组v和e
                    while(expression[idx2] != ')' && expression[idx2] != ' ') {
                        idx2++;
                    }
                    string paramName = expression.substr(idx1, idx2 - idx1);
                    if(expression[idx2] == ')') { // 变量或者数字也可以是e
                        // 是数字
                        if((expression[idx1] >= '0' && expression[idx1] <= '9') || expression[idx1] == '-') {
                            return atoi(expression.substr(idx1, idx2 - idx1).c_str());
                        }
                        // 是变量
                        identTable *tmp = cur;
                        while(tmp != nullptr && !tmp->idents.count(paramName)) {
                            tmp = tmp->prev;
                        }

                        if(tmp == nullptr) {
                            cout << "wrong paramName" << endl;
                            return 0;
                        }
                        else {
                            return tmp->idents[paramName];
                        }
                    }

                    int param;
                    idx1 = idx2 + 1;
                    idx2 = idx1;

                    if(expression[idx1] == '(') { // 是一个子表达式
                        int blockCnt = 1;
                        while(blockCnt != 0) {
                            idx2++;
                            if(expression[idx2] == '(')
                                blockCnt++;
                            if(expression[idx2] == ')')
                                blockCnt--;
                        }
                        // idx2 在右括号
                        idx2++; // 在空格
                        param = evaluateSubExp(expression.substr(idx1, idx2 - idx1), idx1, idx2 - idx1, cur);
                    }
                        // 是数字
                    else if((expression[idx1] >= '0' && expression[idx1] <= '9') || expression[idx1] == '-'){
                        while(expression[idx2] != ')' && expression[idx2] != ' ') {
                            idx2++;
                        }
                        param = atoi(expression.substr(idx1, idx2 - idx1).c_str());
                    }
                    else { // 是变量
                        while(expression[idx2] != ')' && expression[idx2] != ' ') {
                            idx2++;
                        }
                        string paramName2 = expression.substr(idx1, idx2 - idx1);
                        identTable *tmp = cur;
                        while(tmp != nullptr && !tmp->idents.count(paramName2)) {
                            tmp = tmp->prev;
                        }

                        if(tmp == nullptr) {
                            cout << "wrong paramName2" << endl;
                            return 0;
                        }
                        else {
                            param = tmp->idents[paramName2];
                        }
                    }
                    cur->idents[paramName] = param;
                }
            }
        }
        else if(op == "add" || op == "mult") {
            idx1 = idx2 + 1;
            idx2 = idx1;
            int param1, param2;
            if(expression[idx1] == '(') { // 是一个子表达式
                int blockCnt = 1;
                while(blockCnt != 0) {
                    idx2++;
                    if(expression[idx2] == '(')
                        blockCnt++;
                    if(expression[idx2] == ')')
                        blockCnt--;
                }
                // idx2 在右括号
                idx2++; // 在空格
                param1 = evaluateSubExp(expression.substr(idx1, idx2 - idx1), idx1, idx2 - idx1, cur);
            }
            else if((expression[idx1] >= '0' && expression[idx1] <= '9') || expression[idx1] == '-'){ // 是数字
                while(expression[idx2] != ')' && expression[idx2] != ' ') {
                    idx2++;
                }
                param1 = atoi(expression.substr(idx1, idx2 - idx1).c_str());
            }
            else { // 是变量
                while(expression[idx2] != ')' && expression[idx2] != ' ') {
                    idx2++;
                }
                string paramName = expression.substr(idx1, idx2 - idx1);
                identTable *tmp = cur;
                while(tmp != nullptr && !tmp->idents.count(paramName)) {
                    tmp = tmp->prev;
                }

                if(tmp == nullptr) {
                    cout << "wrong paramName" << endl;
                    return 0;
                }
                else {
                    param1 = tmp->idents[paramName];
                }
            }
            idx1 = idx2 + 1;
            idx2 = idx1;
            if(expression[idx1] == '(') { // 是一个子表达式
                int blockCnt = 1;
                while(blockCnt != 0) {
                    idx2++;
                    if(expression[idx2] == '(')
                        blockCnt++;
                    if(expression[idx2] == ')')
                        blockCnt--;
                }
                // idx2 在右括号
                idx2++; // 在空格
                param2 = evaluateSubExp(expression.substr(idx1, idx2 - idx1), idx1, idx2 - idx1, cur);
            }
            else if((expression[idx1] >= '0' && expression[idx1] <= '9') || expression[idx1] == '-'){ // 是数字
                while(expression[idx2] != ')' && expression[idx2] != ' ') {
                    idx2++;
                }
                param2 = atoi(expression.substr(idx1, idx2 - idx1).c_str());
            }
            else { // 是变量
                while(expression[idx2] != ')' && expression[idx2] != ' ') {
                    idx2++;
                }
                string paramName = expression.substr(idx1, idx2 - idx1);
                identTable *tmp = cur;
                while(tmp != nullptr && !tmp->idents.count(paramName)) {
                    tmp = tmp->prev;
                }

                if(tmp == nullptr) {
                    cout << "wrong paramName" << endl;
                    return 0;
                }
                else {
                    param2 = tmp->idents[paramName];
                }
            }

            if(op == "add") {
                return param1 + param2;
            }
            else {
                return param1 * param2;
            }
        }
        else {
            cout << "something wrong" << endl;
        }

        return 0;
    }

    int evaluate(string expression) {
        identTable *head = nullptr;
        return evaluateSubExp(expression, 0, expression.length(), head);
    }
};