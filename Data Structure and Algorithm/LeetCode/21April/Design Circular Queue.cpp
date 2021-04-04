class MyCircularQueue {
public:
    int Qbuffer[1001];
    int Qsize, f, r;
    
    MyCircularQueue(int k) {
        Qsize = k+1;
        f = r = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        r = (r+1)%Qsize;
        Qbuffer[r] = value;
        cout << Qbuffer[r] << " " << r << "\n";
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f = (f+1)%Qsize;
        cout << Qbuffer[f] << " " << f << "\n";
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return Qbuffer[(f+1)%Qsize];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return Qbuffer[r];
    }
    
    bool isEmpty() {
        return f == r;
    }
    
    bool isFull() {
        cout << f << " " << r << " " << Qsize <<"\n";
        return (r+1)%Qsize == f;
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
