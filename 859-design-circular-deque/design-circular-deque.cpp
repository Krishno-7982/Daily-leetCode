class MyCircularDeque {
public:
    int MAX;
    int f = -1;
    int r = -1;
    int cnt = 0;
    vector<int> q;

    MyCircularDeque(int k) {
        MAX = k;
        q.resize(MAX);
    }
    
    bool insertFront(int value) {
        if(cnt == MAX) {
            return false;
        }

        if(f == -1) {
            f = r = 0;
        } else {
            f = (f - 1 + MAX) % MAX;
        }

        q[f] = value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cnt == MAX) {
            return false;
        }

        if(f == -1) {
            f = r = 0;
        } else {
            r = (r + 1) % MAX;
        }

        q[r] = value;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(cnt == 0) {
            return false;
        }

        if(f == r) {
            f = r = -1;
        } else {
            f = (f + 1) % MAX;
        }

        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(cnt == 0) {
            return false;
        }

        if(f == r) {
            f = r = -1;
        } else {
            r = (r - 1 + MAX) % MAX;
        }

        cnt--;
        return true;
    }
    
    int getFront() {
        if(cnt == 0) {
            return -1;
        }

        return q[f];
    }
    
    int getRear() {
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