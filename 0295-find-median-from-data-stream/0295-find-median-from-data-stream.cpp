class MedianFinder {
public:
    priority_queue<int>p;
    priority_queue<int,vector<int>,greater<int>>q;
    
    void addNum(int num) {
        p.push(num);
        while(p.size()>q.size()){
            q.push(p.top());
            p.pop();
        }
        while(q.size()>p.size()){
            p.push(q.top());
            q.pop();
        }
    }
    
    double findMedian() {
        if((p.size()+q.size())&1)
            return p.size()>q.size()?p.top():q.top();
        return (double)(p.top()+q.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */