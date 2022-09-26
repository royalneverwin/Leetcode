class MyLinkedList {
    int cnt;
    // 单向链表
    class Node {
    public:
        int val;
        Node *next;
        Node(int v) {
            val = v;
            next = nullptr;
        }
    };

    Node *head;

public:
    MyLinkedList() {
        cnt = 0;
        head = nullptr;
    }

    int get(int index) {
        if (index >= cnt)
            return -1;
        if(index < 0)
            return -1;

        int idx = 0;
        Node *tmp = head;
        while(idx < index) {
            tmp = tmp->next;
            idx++;
        }

        return tmp->val;
    }

    void addAtHead(int val) {
        Node *newOne = new Node(val);
        if(head != nullptr) {
            newOne->next = head;
        }
        head = newOne;
        cnt++;
        // Node *tmp = head;
        // while(tmp->next != nullptr) {
        //     cout << tmp->val << ' ';
        //     tmp = tmp->next;
        // }
        // cout << tmp->val << endl;
    }

    void addAtTail(int val) {
        Node *newOne = new Node(val);
        if(head == nullptr)
            head = newOne;
        else {
            Node *tmp = head;
            while(tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = newOne;
        }
        cnt++;
        // Node *tmp = head;
        // while(tmp->next != nullptr) {
        //     cout << tmp->val << ' ';
        //     tmp = tmp->next;
        // }
        // cout << tmp->val << endl;
    }

    void addAtIndex(int index, int val) {
        if(index == cnt) {
            addAtTail(val);
        }
        else if(index <= 0){
            addAtHead(val);
        }
        else if(index < cnt) {
            int idx = 0;
            Node *tmp = head;
            while(idx < index-1) {
                tmp = tmp->next;
                idx++;
            }
            Node *nxt = tmp->next;
            Node *newOne = new Node(val);
            newOne->next = nxt;
            tmp->next = newOne;
            cnt++;
            // tmp = head;
            // while(tmp->next != nullptr) {
            //     cout << tmp->val << ' ';
            //     tmp = tmp->next;
            // }
            // cout << tmp->val << endl;
        }
    }

    void deleteAtIndex(int index) {
        if(index == 0) {
            Node *tmp = head;
            head = tmp->next;
            delete tmp;
            cnt--;
        }
        else if(index > 0 && index < cnt) {
            int idx = 0;
            Node *tmp = head;
            while(idx < index-1) {
                tmp = tmp->next;
                idx++;
            }
            Node *cur = tmp->next;
            tmp->next = cur->next;

            delete cur;
            cnt--;
        }
        // Node *tmp = head;
        // while(tmp->next != nullptr) {
        //     cout << tmp->val << ' ';
        //     tmp = tmp->next;
        // }
        // cout << tmp->val << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */