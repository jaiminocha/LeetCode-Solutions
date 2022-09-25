class MyCircularQueue {
public:
    vector<int> v;
    int s, e, size;
    MyCircularQueue(int k) {
        s = 0;
        e = 0;
        size = 0;
        v.resize(k, -1);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()){
            s = e = 0;
            v[e] = value;
            size++;
            return true;
        }
        size++;
        e++;
        e = (e % v.size());
        v[e] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        v[s] == -1;
        s++;
        size--;
        s = (s % v.size());
        return true;
    }
    
    int Front() {
        if (!isEmpty()){
            return v[s];
        }
        return -1;
    }
    
    int Rear() {
        if (isEmpty()){
            return -1;
        }
        return v[e];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return v.size() == size;
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