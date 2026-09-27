class MyCircularQueue {
public:
    int MAX;
    int f = -1;
    int r = -1;
    int cnt = 0;
    vector<int> q;

    MyCircularQueue(int k) {
        MAX = k;
        q.resize(MAX);
    }
    
    bool enQueue(int value) {
        if(cnt == MAX) {
            return false;
        }

        if(cnt == 0) {
            f = r = 0;
        }
        else {
            r = (r + 1) % MAX;
        }

        q[r] = value;
        cnt++;

        return true;
    }
    
    bool deQueue() {
        if(cnt == 0) {
            return false;
        }

        if(cnt == 1) {
            f = r = -1;
        }
        else {
            f = (f + 1) % MAX;
        }

        cnt--;

        return true;
    }
    
    int Front() {
        if(cnt == 0) {
            return -1;
        }

        return q[f];
    }
    
    int Rear() {
        if(cnt == 0) {
            return -1;
        }

        return q[r];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == MAX;
    }
};