class MedianFinder {
public:
    // Smaller half
    priority_queue<double> pqf;

    // Larger half
    priority_queue<double, vector<double>, greater<double>> pfs;

    MedianFinder() {
    }

    void addNum(int num) {

        // Decide which half the number belongs to
        if (pqf.empty() || num <= pqf.top()) {
            pqf.push(num);
        }
        else {
            pfs.push(num);
        }

        // Balance the heaps
        if (pqf.size() > pfs.size() + 1) {
            pfs.push(pqf.top());
            pqf.pop();
        }
        else if (pfs.size() > pqf.size()) {
            pqf.push(pfs.top());
            pfs.pop();
        }
    }

    double findMedian() {

        if (pqf.size() == pfs.size()) {
            return (pqf.top() + pfs.top()) / 2.0;
        }

        return pqf.top();
    }
};