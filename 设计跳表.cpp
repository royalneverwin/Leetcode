class Node {
public:
    int val;
    int cnt;
    Node *right;
    Node *down;
    Node(int v=-1) {
        val = v;
        cnt = 1;
        right = nullptr;
        down = nullptr;
    }
};

#define MAX_LEVEL 32
// 注意 跳表中可以存在相同值
class Skiplist {
    Node *head;
    int level;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;

public:
    Skiplist() {
        head = new Node(-1);
    }

    void Show() {
        cout << "begin: " << endl;
        Node *tmp = head;
        while(tmp) {
            Node *tmp1 = tmp;
            while(tmp1) {
                cout << tmp1->val << ',' << tmp1->cnt << ' ';
                tmp1 = tmp1->right;
            }
            cout << endl;
            tmp = tmp->down;
        }
    }

    bool search(int target) {
        Node *cur = head;
        while(cur) {
            if(cur->val == target)
                return true;
            else if(cur->right == nullptr) {
                cur = cur->down;
            }
            else if(cur->right->val > target) {
                cur = cur->down;
            }
            else {
                cur = cur->right;
            }
        }
        return false;
    }

    void add(int num) {
        vector<Node *> prevList;
        Node *cur = head;
        while(cur) {
            if(cur->val == num) { // 已经插入过了 cnt+1
                while(cur) {
                    cur->cnt++;
                    cur = cur->down;
                }
                return;
            }
            else if(cur->right == nullptr) {
                prevList.emplace_back(cur);
                cur = cur->down;
            }
            else if(cur->right->val > num) {
                prevList.emplace_back(cur);
                cur = cur->down;
            }
            else {
                cur = cur->right;
            }
        }
        int length = prevList.size();
        Node *newn = new Node;
        newn->val = num;
        newn->right = prevList[length-1]->right;
        prevList[length-1]->right = newn;
        newn->down = nullptr;
        Node *prevn = newn;
        int i = length - 2;
        for(; i >= 0; i--) {
            if(dis(gen) > 0.5) {
                newn = new Node(num);
                newn->right = prevList[i]->right;
                prevList[i]->right = newn;
                newn->down = prevn;
                prevn = newn;
            }
            else {
                break;
            }
        }

        // 随机再生成最上一层 一定要是最上面一层有的情况下
        if(length < MAX_LEVEL && i == -1 && dis(gen) > 0.5) {
            Node *newhead = new Node;
            newhead->down = head;
            newn = new Node(num);
            newn->right = nullptr;
            newn->down = prevn;
            newhead->right = newn;
            head = newhead;
        }

    }

    bool erase(int num) {
        Node *cur = head;
        bool flag = false;
        while(cur) {
            if(cur->right == nullptr) {
                cur = cur->down;
            }
            else if(cur->right->val == num) { // 注意不是遍历到再删 而是遍历到的它的前一个节点就开始删了
                if(cur->right->cnt == 1) {
                    Node *tmp = cur->right;
                    cur->right = cur->right->right;
                    delete tmp;
                    cur = cur->down;
                    flag = true;
                }
                else {
                    cur = cur->right;
                    while(cur) {
                        cur->cnt--;
                        cur = cur->down;
                    }
                    return true;
                }
            }
            else if(cur->right->val > num) {
                cur = cur->down;
            }
            else {
                cur = cur->right;
            }
        }
        return flag;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */