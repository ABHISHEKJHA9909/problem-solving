class MyStack {
private:
    queue<int>q;
    int _top=-1;
    int size=0;
public:
    void push(int x) {
        q.push(x);
        _top=x;
        ++size;
    }
    
    int pop() {
        
        for(int i=0;i<size-2;i++){
            q.push(q.front());
            q.pop();
        }
        if(size>=2){
            _top=q.front();
            q.pop();
            q.push(_top);
        }
        int curr=q.front();
        q.pop();
        
        --size;
        return curr;
    }
    
    int top() {
        return _top;
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */