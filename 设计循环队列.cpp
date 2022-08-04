class MyCircularQueue {
    vector<int> qu;
    int front; // 指向队列头
    int rear; // 指向队列尾的后一个
    int length;
public:
    MyCircularQueue(int k) {
        qu = vector<int>(k);
        front = -1;
        rear = 0;
        length = k;
    }

    bool enQueue(int value) {
        if(rear == front)
            return false;
        else {
            qu[rear] = value;
            rear = (rear+1) % length;
            if(front == -1)
                front = 0;
            return true;
        }
    }

    bool deQueue() {
        if(front == -1)
            return false;
        else {
            front = (front+1) % length;
            if(front == rear) {
                front = -1;
                rear = 0;
            }
            return true;
        }
    }

    int Front() {
        if(front == -1)
            return -1;
        else
            return qu[front];
    }

    int Rear() {
        if(front == -1)
            return -1;
        else {
            if(rear == 0)
                return qu[length-1];
            else
                return qu[rear-1];
        }
    }

    bool isEmpty() {
        return front==-1;
    }

    bool isFull() {
        return front==rear;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */