class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            pq.push(i);
    }
    
    int popSmallest() {
        int temp=pq.top();
        while(pq.size() && pq.top()==temp)
            pq.pop();
        return temp;
    }
    
    void addBack(int num) {
        if(num<=1000)
            pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */