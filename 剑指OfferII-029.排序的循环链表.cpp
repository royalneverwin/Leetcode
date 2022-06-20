/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL) {
            Node *newOne = new Node;
            newOne->val = insertVal;
            newOne->next = newOne;
            return newOne;
        }
        else if(head->next == head) {
            Node *newOne = new Node;
            newOne->val = insertVal;
            newOne->next = head;
            head->next = newOne;
            return head;
        }
        Node *cur = head;
        Node *nxt = head->next;
        while(1) {
            if(nxt->val >= cur->val) { // 还在升序
                if(insertVal < cur->val) { // 继续往后找 找一个循环
                    cur = cur->next;
                    nxt = cur->next;
                    if(cur == head) { // 找了一圈了都一样
                        Node *newOne = new Node;
                        newOne->val = insertVal;
                        newOne->next = nxt;
                        cur->next = newOne;
                        return head;
                    }
                    continue;
                }
                else { // 看看是否在现在和下一个之间
                    if(insertVal <= nxt->val) {
                        Node *newOne = new Node;
                        newOne->val = insertVal;
                        cur->next = newOne;
                        newOne->next = nxt;
                        break;
                    }
                    else {
                        cur = cur->next;
                        nxt = cur->next;
                        continue;
                    }
                }
            }
            else { // 降序了
                if(insertVal < cur->val) {
                    // 看看是否比nxt也小
                    if(insertVal <= nxt->val) {
                        Node *newOne = new Node;
                        newOne->val = insertVal;
                        cur->next = newOne;
                        newOne->next = nxt;
                        break;
                    }
                    else {
                        cur = cur->next;
                        nxt = cur->next;
                        continue;
                    }
                }
                else {
                    Node *newOne = new Node;
                    newOne->val = insertVal;
                    cur->next = newOne;
                    newOne->next = nxt;
                    break;
                }
            }
        }
        return head;
    }
};