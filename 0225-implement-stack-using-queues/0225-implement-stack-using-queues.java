class MyStack {
    private Queue<Integer>q;
    
    public MyStack() {
        q=new LinkedList<>();
    }
    
    public void push(int x) {
        q.add(x);
    }
    
    public int pop() {
        int size=q.size();
        for(int i=0;i<size-1;++i){
            q.add(q.poll());
        }
        return q.poll();
    }
    
    public int top() {
        int size=q.size();
        for(int i=0;i<size-1;++i){
            q.add(q.poll());
        }
        
        int result=q.poll();
        q.add(result);
        return result;
    }
    
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */