class MedianFinder {
private:
    priority_queue<double> leftHeap;
    priority_queue<double, vector<double>, greater<double> > rightHeap;
    double med;
public:
    MedianFinder() {
        med = 0;
    }
    
    void addNum(int num) {
        if (leftHeap.size() == 0 && rightHeap.size() == 0) {
            med = num;
            leftHeap.push(num);
        }
        else if (leftHeap.size() > rightHeap.size()){
            if (num > med){
                rightHeap.push(num);
            }
            else {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }
            med = (leftHeap.top() + rightHeap.top())/2.0;
        }
        else if (leftHeap.size() < rightHeap.size()){
            if (num > med){
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }
            else {
                leftHeap.push(num);
            }
            med = (leftHeap.top() + rightHeap.top())/2.0;
        }
        else {
            if (num > med){
                rightHeap.push(num);
                med = rightHeap.top();
            }
            else {
                leftHeap.push(num);
                med = leftHeap.top();
            }
        }
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */